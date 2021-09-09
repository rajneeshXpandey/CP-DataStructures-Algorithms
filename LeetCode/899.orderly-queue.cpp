/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {

        int n = s.size();
        string ans = s;
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
            {
                s = s.substr(1) + s[0];
                ans = min(ans, s);
            }
            return ans;
        }
        sort(s.begin(), s.end());

        return s;
    }
};
// @lc code=end

