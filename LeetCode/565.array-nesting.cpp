/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(),cyc = 0,ans = 0;
        vector<bool> visi(n,0);
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            int j = i;
            cyc = 0;
            while (!visi[j])
            {
                visi[j] = 1;
                j = nums[j];
                cyc++;
            }
            ans = max(cyc,ans);
        }
        return ans;
    }
};
// @lc code=end

