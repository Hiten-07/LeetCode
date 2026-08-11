#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        // Step 1: find longest sequential prefix
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) sum += nums[i];
            else break;
        }
        // Step 2: put all nums in a set
        unordered_set<int> st(nums.begin(), nums.end());
        // Step 3: find smallest missing >= sum
        int x = sum;
        while (st.count(x)) x++;
        return x;
    }
};
