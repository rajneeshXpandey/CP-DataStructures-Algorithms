/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution
{
public:
    bool unique(string &s)
    {
        unordered_map<char, int> mp;
        for (auto ch : s)
            mp[ch]++;
        return (mp.size() == s.size());
    }
    vector<string> subseq;
    void generate_sub(vector<string> input, string output)
    {
        if (input.size() == 0)
        {
            subseq.push_back(output);
            return;
        }
        string output1 = "";
        output1.append(input[input.size() - 1]);
        output1.append(output);
        input.pop_back();
        if (unique(output1))
            generate_sub(input, output1);
        if (unique(output))
            generate_sub(input, output);
    }
    int maxLength(vector<string> &arr)
    {
        int ans = 0, len = 0;
        generate_sub(arr, "");
        for (auto str : subseq)
        {
            len = str.size();
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

