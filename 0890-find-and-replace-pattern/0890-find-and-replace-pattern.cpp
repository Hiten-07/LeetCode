class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto normalize = [](string s) {
            unordered_map<char,int> mp;
            vector<int> form;
            int id = 0;
            for (char c : s) {
                if (!mp.count(c)) mp[c] = id++;
                form.push_back(mp[c]);
            }
            return form;
        };

        vector<int> patForm = normalize(pattern);
        vector<string> ans;
        for (string w : words) {
            if (normalize(w) == patForm) ans.push_back(w);
        }
        return ans;
    }
};
