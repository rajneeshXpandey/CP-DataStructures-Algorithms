/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0, i = 0, j = 0, cnt = 0;
        while (j < n)
        {
            if (nums[j] == 0)
                cnt++;
            if (cnt <= k)
            {
                ans = max(ans, j - i + 1);
            }
            if (cnt > k)
            {
                while (i < n and nums[i] != 0)
                    i++;
                i++;
                cnt--;
            }
            j++;
        }

        return ans;
    }
};
// @lc code=end

