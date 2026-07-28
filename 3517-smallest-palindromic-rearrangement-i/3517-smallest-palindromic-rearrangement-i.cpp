class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string left = "", mid = "";
        for (int i = 0; i < 26; i++) {
            int half = freq[i] / 2;
            left.append(half, 'a' + i);
            if (freq[i] % 2 == 1) mid.push_back('a' + i);
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};
