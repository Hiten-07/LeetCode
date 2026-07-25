class Solution {
public:
    int maxProduct(int num) {
        string s = to_string(num);
        int first = 0, second = 0;
        for (char c : s) {
            int d = c - '0';
            if (d > first) {
                second = first;
                first = d;
            } else if (d > second) {
                second = d;
            }
        }
        return first * second;
    }
};
