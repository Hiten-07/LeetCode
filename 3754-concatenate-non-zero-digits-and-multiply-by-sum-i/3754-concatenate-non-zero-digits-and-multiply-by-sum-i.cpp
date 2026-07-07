class Solution {
public:
    long long sumAndMultiply(int n) {
        string digits = to_string(n);
        long long x = 0, s = 0;

        for (char c : digits) {
            if (c != '0') {
                x = x * 10 + (c - '0');
                s += (c - '0');
            }
        }

        return x * s;
    }
};