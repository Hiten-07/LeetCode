class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = n / 2;
        auto isVowel = [](char c) {
            c = tolower(c);
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        
        int countA = 0, countB = 0;
        for (int i = 0; i < mid; i++) if (isVowel(s[i])) countA++;
        for (int i = mid; i < n; i++) if (isVowel(s[i])) countB++;
        
        return countA == countB;
    }
};
