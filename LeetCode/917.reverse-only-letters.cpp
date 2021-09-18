/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        string res = "";
        for (auto ch : s)
        {
            if ((ch >= 65 and ch <= 90) or (ch >= 97 and ch <= 122))
            {
                res += ch;
            }
        }
        reverse(res.begin(), res.end());
        string ans = "";
        int i = 0;
        for (auto ch : s)
        {
            if ((ch >= 65 and ch <= 90) or (ch >= 97 and ch <= 122))
            {
                ans += res[i];
                i++;
            }
            else
                ans += ch;
        }
        return ans;

        // solution 2 : use two pointer to swap the required chars
    }
};
// @lc code=end

