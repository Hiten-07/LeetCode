class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0, e = 0;
                stack<int> st;
                st.push(i);
                vis[i] = 1;

                while (!st.empty()) {
                    int u = st.top(); st.pop();
                    v++;
                    e += adj[u].size();
                    for (int nei : adj[u]) {
                        if (!vis[nei]) {
                            vis[nei] = 1;
                            st.push(nei);
                        }
                    }
                }

                e /= 2; // undirected edges counted twice
                if (e == v * (v - 1) / 2) ans++;
            }
        }
        return ans;
    }
};
