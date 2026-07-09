class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                       vector<vector<int>>& queries) {
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++)
            comp[i] = comp[i-1] + (nums[i] - nums[i-1] > maxDiff ? 1 : 0);

        vector<bool> ans;
        for (auto& q : queries)
            ans.push_back(comp[q[0]] == comp[q[1]]);

        return ans;
    }
};