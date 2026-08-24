class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Build prefix sum in-place
        for (int i = 1; i < n; i++)
            stones[i] += stones[i-1];

        // dp[i] = best score diff for current player picking from index i..n-1
        // Start from the right: base case dp[n-1] = prefix[n-1]
        int dp = stones[n-1]; // represents dp[n-1]

        // Fill from i = n-2 down to i = 1
        for (int i = n-2; i >= 1; i--)
            dp = max(stones[i] - dp, dp);

        return dp;
    }
};