#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }
        
        int ans = 0;
        for (auto &row : mp) {
            bool left = !(row.second.count(2) || row.second.count(3) || row.second.count(4) || row.second.count(5));
            bool right = !(row.second.count(6) || row.second.count(7) || row.second.count(8) || row.second.count(9));
            bool middle = !(row.second.count(4) || row.second.count(5) || row.second.count(6) || row.second.count(7));
            
            if (left && right) ans += 2;
            else if (left || right) ans += 1;
            else if (middle) ans += 1;
        }
        
        // Rows without reservations can seat 2 families
        ans += (n - mp.size()) * 2;
        return ans;
    }
};
