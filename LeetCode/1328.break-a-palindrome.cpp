/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() == 1)
            return "";
        int l = 0, r = palindrome.size() - 1;
        while (l < r)
        {
            if (palindrome[l] != 'a')
            {
                palindrome[l] = 'a';
                return palindrome;
            }
            l++;
            r--;
        }
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};
// @lc code=end

