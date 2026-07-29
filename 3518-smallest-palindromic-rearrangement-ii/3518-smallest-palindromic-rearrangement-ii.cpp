class Solution {
    const long long MAX = 1e6 + 1;

    // nCk capped at MAX
    long long nCk(long long n, long long k) {
        k = min(k, n - k);
        long long res = 1;
        for (long long i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX) return MAX;
        }
        return res;
    }

    // Count distinct arrangements of halfCount characters, capped at MAX
    long long countArrangements(vector<int>& cnt) {
        long long total = 0;
        for (int c : cnt) total += c;
        long long res = 1;
        for (int c : cnt) {
            res *= nCk(total, c);
            if (res >= MAX) return MAX;
            total -= c;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // Build half count and middle character
        vector<int> halfCnt(26, 0);
        string mid = "";
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = freq[i] / 2;
            if (freq[i] % 2 == 1) mid = string(1, 'a' + i);
        }

        // Check if k-th permutation exists
        long long total = countArrangements(halfCnt);
        if (k > total) return "";

        // Greedily build left half
        string leftHalf = "";
        int halfLen = s.size() / 2;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0) continue;
                halfCnt[c]--;
                long long arrangements = countArrangements(halfCnt);
                if (arrangements >= k) {
                    leftHalf += (char)('a' + c);
                    break;
                } else {
                    k -= arrangements;
                    halfCnt[c]++;
                }
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + mid + rightHalf;
    }
};