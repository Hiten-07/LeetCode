#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0, maxRight = -1;
        for (auto &iv : intervals) {
            if (iv[1] > maxRight) {
                count++;
                maxRight = iv[1];
            }
            // else covered, skip
        }
        return count;
    }
};
