// The API guess is defined for you.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res < 0) r = mid - 1;
            else l = mid + 1;
        }
        return -1; // should never reach here
    }
};
