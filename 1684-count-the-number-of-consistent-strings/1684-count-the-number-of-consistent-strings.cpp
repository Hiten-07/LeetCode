class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> ok(26, false);
        for (char c : allowed) ok[c - 'a'] = true;

        int ans = 0;
        for (string &w : words) {
            bool consistent = true;
            for (char c : w) {
                if (!ok[c - 'a']) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) ans++;
        }
        return ans;
    }
};
