#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> count(3, 0); // counts for a,b,c
        int ans = 0, left = 0;
        
        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n - right); // all substrings ending at >= right
                count[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};
