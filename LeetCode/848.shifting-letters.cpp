/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long> shift(n);
        shift[n - 1] = shifts[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            shift[i] = shifts[i] + shift[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            s[i] = (s[i] + shift[i] - 'a') % 26 + 'a';
        }
        return s;
    }
};
// @lc code=end

