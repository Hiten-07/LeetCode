class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // cnt[x] = frequency of x in nums
        vector<int> cnt(mx + 1, 0);
        for (int x : nums) cnt[x]++;

        // cntG[g] = number of pairs with GCD exactly g
        vector<long long> cntG(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long v = 0;
            // Count elements divisible by g
            for (int mult = g; mult <= mx; mult += g) {
                v += cnt[mult];
                cntG[g] -= cntG[mult]; // subtract pairs with GCD = mult (mult > g)
            }
            cntG[g] += v * (v - 1) / 2; // total pairs divisible by g
        }

        // Build prefix sum of cntG
        for (int g = 1; g <= mx; g++)
            cntG[g] += cntG[g - 1];

        // Answer each query with binary search
        vector<int> ans;
        for (long long q : queries) {
            // Find smallest g where prefix[g] > q
            int lo = 1, hi = mx, res = mx;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (cntG[mid] > q) { res = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            ans.push_back(res);
        }

        return ans;
    }
};