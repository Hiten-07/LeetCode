class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Suffix sums
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + stoneValue[i];

        // dp[i] = best score difference from index i onward
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                int take = suffix[i] - suffix[i + k];
                dp[i] = max(dp[i], take - dp[i + k]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};