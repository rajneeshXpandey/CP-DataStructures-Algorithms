/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long ans = 0, n = nums.size();
        vector<pair<long long, unordered_map<long long, long long>>> seq(n);
        if (n < 3)
            return ans;
        for (int i = 0; i < n; i++)
        {
            seq[i].first = nums[i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                long long d = seq[i].first - seq[j].first;
                if (seq[j].second.find(d) != seq[j].second.end())
                {
                    long long prev = (seq[j].second.find(d))->second;
                    ans += prev;
                    seq[i].second[d] += (prev + 1);
                }
                else
                {
                    seq[i].second[d] += 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

