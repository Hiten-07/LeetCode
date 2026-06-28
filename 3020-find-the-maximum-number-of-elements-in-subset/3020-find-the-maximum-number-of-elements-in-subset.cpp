class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        unordered_map<long long, int> count;
        for (int num : nums) ++count[num];

        // Handle base 1 specially: any odd count of 1's works
        int ans = count.count(1) ? count[1] - (count[1] % 2 == 0) : 1;

        for (int num : nums) {
            if (num == 1) continue;

            int length = 0;
            long long x = num;

            // Keep squaring while we have at least 2 copies (need pairs for both sides)
            while (x <= maxNum && count.count(x) && count[x] >= 2) {
                length += 2;
                x *= x;
            }

            // x is now the potential "peak" of the palindrome — only needs 1 copy
            if (x <= maxNum && count.count(x))
                length += 1;
            else
                length -= 1; // overshot: undo the last pair since no peak exists

            ans = max(ans, length);
        }

        return ans;
    }
};