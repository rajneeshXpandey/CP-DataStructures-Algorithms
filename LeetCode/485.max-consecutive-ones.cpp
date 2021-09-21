/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0, len = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                len++;
            }
            else
            {
                len = 0;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};
// @lc code=end

