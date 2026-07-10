class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned;
        for (char c : s) {
            if (c != '-') cleaned.push_back(toupper(c));
        }
        
        string result;
        int firstGroup = cleaned.size() % k;
        int idx = 0;
        
        if (firstGroup > 0) {
            result.append(cleaned.substr(0, firstGroup));
            idx = firstGroup;
            if (idx < cleaned.size()) result.push_back('-');
        }
        
        while (idx < cleaned.size()) {
            result.append(cleaned.substr(idx, k));
            idx += k;
            if (idx < cleaned.size()) result.push_back('-');
        }
        
        return result;
    }
};
