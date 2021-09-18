/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();
        if (n == 1)
            return 1;
        int imax = 0;
        int l = 0, i = 0;
        while (i < n - 1)
        {
            if (arr[i] > arr[i + 1] and i % 2)
                l++;
            else if (arr[i] < arr[i + 1] and i % 2 == 0)
                l++;
            else
                l = 0;
            i++;
            imax = max(l + 1, imax);
        }
        l = 0, i = 0;
        while (i < n - 1)
        {
            if (arr[i] < arr[i + 1] and i % 2)
                l++;
            else if (arr[i] > arr[i + 1] and i % 2 == 0)
                l++;
            else
                l = 0;
            i++;
            imax = max(l + 1, imax);
        }

        return imax;
    }
};
// @lc code=end

