#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int maxEdge = 0;
        for (auto &e : edges) {
            int u=e[0], v=e[1], w=e[2];
            if (!online[u] || !online[v]) continue; // skip offline nodes
            adj[u].push_back({v,w});
            maxEdge = max(maxEdge, w);
        }

        auto can = [&](int score) {
            // only consider edges >= score
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;
            queue<int> q;
            vector<int> indeg(n,0);
            vector<vector<pair<int,int>>> g(n);
            for (int u=0;u<n;u++) {
                if (!online[u]) continue;
                for (auto [v,w]: adj[u]) {
                    if (w >= score) {
                        g[u].push_back({v,w});
                        indeg[v]++;
                    }
                }
            }
            // topological order
            queue<int> topo;
            for (int i=0;i<n;i++) if (indeg[i]==0 && online[i]) topo.push(i);
            while (!topo.empty()) {
                int u=topo.front(); topo.pop();
                for (auto [v,w]: g[u]) {
                    if (dist[u]!=LLONG_MAX && dist[u]+w < dist[v]) {
                        dist[v] = dist[u]+w;
                    }
                    indeg[v]--;
                    if (indeg[v]==0) topo.push(v);
                }
            }
            return dist[n-1] <= k;
        };

        int lo=0, hi=maxEdge, ans=-1;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (can(mid)) {
                ans=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        return ans;
    }
};
