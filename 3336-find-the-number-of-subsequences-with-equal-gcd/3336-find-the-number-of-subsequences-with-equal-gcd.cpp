class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const int MAXV = 201;

        // dp[g1][g2] = number of ways to pick two disjoint subsequences
        //              with GCD g1 and GCD g2 respectively (0 means empty)
        vector<vector<long long>> dp(MAXV, vector<long long>(MAXV, 0));

        for (int num : nums) {
            // Iterate in reverse to avoid using num twice in same update
            // Update dp[g1][g2] by adding num to seq1, seq2, or neither
            vector<vector<long long>> ndp = dp; // neither: carry forward

            for (int g1 = 0; g1 < MAXV; g1++) {
                for (int g2 = 0; g2 < MAXV; g2++) {
                    if (dp[g1][g2] == 0 && g1 != 0 && g2 != 0) continue;
                    long long ways = (g1 == 0 && g2 == 0) ? 1 : dp[g1][g2];
                    if (ways == 0) continue;

                    int ng1 = (g1 == 0) ? num : __gcd(g1, num);
                    int ng2 = (g2 == 0) ? num : __gcd(g2, num);

                    // Add num to seq1
                    ndp[ng1][g2] = (ndp[ng1][g2] + ways) % MOD;
                    // Add num to seq2
                    ndp[g1][ng2] = (ndp[g1][ng2] + ways) % MOD;
                    // ndp[g1][g2] already covers "neither"
                }
            }
            dp = ndp;
        }

        // Sum all dp[g][g] for g >= 1
        long long ans = 0;
        for (int g = 1; g < MAXV; g++)
            ans = (ans + dp[g][g]) % MOD;

        return (int)ans;
    }
};