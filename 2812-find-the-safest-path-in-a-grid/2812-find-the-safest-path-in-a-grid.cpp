#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc] > dist[r][c]+1) {
                    dist[nr][nc] = dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        // Check function: can we reach with safeness >= v?
        auto can = [&](int v) {
            if (dist[0][0] < v) return false;
            vector<vector<bool>> vis(n, vector<bool>(n,false));
            queue<pair<int,int>> q;
            q.push({0,0});
            vis[0][0] = true;
            while (!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                if (r==n-1 && c==n-1) return true;
                for (auto &d : dirs) {
                    int nr=r+d[0], nc=c+d[1];
                    if (nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && dist[nr][nc]>=v) {
                        vis[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
            return false;
        };

        // Binary search on safeness factor
        int lo=0, hi=n*2, ans=0;
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
