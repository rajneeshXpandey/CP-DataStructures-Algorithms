/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if (n < 3)
            return ans;
        for (int i = 0; i < n - 2; i++)
        {
            int prev = nums[i];
            int k = i + 1;
            int d = nums[k] - prev, len = 1;
            while (k < n and nums[k] - prev == d)
            {
                len++;
                prev = nums[k];
                k++;
                if (len >= 3)
                    ans++;
            }
        }

        return ans;
    }
};
// @lc code=end

