#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1)); // max health left at (r,c)

        queue<tuple<int,int,int>> q;
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        q.push({0,0,startHealth});
        best[0][0] = startHealth;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [r,c,h] = q.front(); q.pop();
            if (r == m-1 && c == n-1 && h > 0) return true;

            for (auto &d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0 && nr<m && nc>=0 && nc<n) {
                    int nh = h - grid[nr][nc];
                    if (nh > 0 && nh > best[nr][nc]) {
                        best[nr][nc] = nh;
                        q.push({nr,nc,nh});
                    }
                }
            }
        }
        return false;
    }
};
