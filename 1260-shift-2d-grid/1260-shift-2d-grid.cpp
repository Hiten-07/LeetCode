class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;

        vector<int> arr;
        for (auto &row : grid)
            for (int val : row) arr.push_back(val);

        vector<int> rotated(total);
        for (int i = 0; i < total; i++) {
            rotated[(i + k) % total] = arr[i];
        }

        vector<vector<int>> ans(m, vector<int>(n));
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = rotated[idx++];
            }
        }
        return ans;
    }
};
