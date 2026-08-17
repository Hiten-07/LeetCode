class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        // dp[i][j] = max score on stoneValue[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    int L = prefix[k + 1] - prefix[i];
                    int R = prefix[j + 1] - prefix[k + 1];
                    if (L < R)
                        dp[i][j] = max(dp[i][j], L + dp[i][k]);
                    else if (L > R)
                        dp[i][j] = max(dp[i][j], R + dp[k + 1][j]);
                    else
                        dp[i][j] = max(dp[i][j], L + max(dp[i][k], dp[k + 1][j]));
                }
            }
        }

        return dp[0][n - 1];
    }
};