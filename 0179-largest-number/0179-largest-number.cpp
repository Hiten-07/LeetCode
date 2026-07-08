class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> array;

        for(int num: nums)
            array.push_back(to_string(num));

        // custom comparator
        sort(array.begin(), array.end(), [](const string &a, const string & b)
        {
            return (b + a) < (a + b);
        });

        // if largest number is 0
        if(array[0] == "0")
            return "0";

        // build the largest number
        string largest;
        for(const string &num: array)
            largest += num;

        return largest;
    }
};