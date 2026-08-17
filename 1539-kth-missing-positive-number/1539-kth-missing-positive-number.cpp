#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;
        for (int x : arr) {
            int gap = x - prev - 1;
            if (k <= gap) return prev + k;
            k -= gap;
            prev = x;
        }
        return arr.back() + k;
    }
};
