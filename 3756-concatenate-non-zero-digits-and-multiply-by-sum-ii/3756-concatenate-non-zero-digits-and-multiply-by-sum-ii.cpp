#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1000000007;

        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Prefix arrays
        vector<int> cntN0(n + 1, 0);  // Count of non-zero digits
        vector<int> sumD(n + 1, 0);   // Sum of digits
        vector<long long> p(n + 1, 0); // Concatenated values modulo MOD

        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            
            cntN0[i + 1] = cntN0[i] + (digit != 0 ? 1 : 0);
            sumD[i + 1] = sumD[i] + digit;
            
            if (digit != 0) {
                p[i + 1] = (p[i] * 10 + digit) % MOD;
            } else {
                p[i + 1] = p[i]; // Zeros do not advance the place value
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        // Process range queries in O(1)
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int n0 = cntN0[r + 1] - cntN0[l];
            long long sd = sumD[r + 1] - sumD[l];
            
            // Extract the isolated suffix value by shifting out prefix p[l]
            long long x = (p[r + 1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD;
            
            long long current_ans = (x * sd) % MOD;
            ans.push_back(current_ans);
        }

        return ans;
    }
};
