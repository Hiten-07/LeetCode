class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = *min_element(nums1.begin(), nums1.end());
        if (minVal % 2 == 1) return true; // odd minimum → always possible
        for (int x : nums1) {
            if (x % 2 == 1) return false; // even minimum but odd exists → impossible
        }
        return true; // all even
    }
};
