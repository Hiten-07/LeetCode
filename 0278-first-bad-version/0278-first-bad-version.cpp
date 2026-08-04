// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid; // first bad is at or before mid
            } else {
                l = mid + 1; // first bad is after mid
            }
        }
        return l;
    }
};
