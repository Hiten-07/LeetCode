class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count how many valid amounts <= x
        auto count = [&](long long x) -> long long {
            long long res = 0;
            // Inclusion-exclusion over all non-empty subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = __builtin_popcount(mask);
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        lcm = lcm / __gcd(lcm, (long long)coins[i]) * coins[i];
                        if (lcm > x) { overflow = true; break; } // lcm > x means 0 contribution
                    }
                }
                if (overflow) continue;
                if (bits % 2 == 1) res += x / lcm;
                else               res -= x / lcm;
            }
            return res;
        };

        // Binary search on answer
        long long lo = 1, hi = (long long)*min_element(coins.begin(), coins.end()) * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};