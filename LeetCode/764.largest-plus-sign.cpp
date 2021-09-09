/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));

        for (auto pts : mines)
        {
            grid[pts[0]][pts[1]] = 0;
        }
        vector<vector<int>> left(n, vector<int>(n, 0)), right(n, vector<int>(n, 0)), up(n, vector<int>(n, 0)), down(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            int one = 1;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    left[i][j] = one;
                    one++;
                }
                else
                    one = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int one = 1;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j])
                {
                    right[i][j] = one;
                    one++;
                }
                else
                    one = 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            int one = 1;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][j])
                {
                    up[i][j] = one;
                    one++;
                }
                else
                    one = 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            int one = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (grid[i][j])
                {
                    down[i][j] = one;
                    one++;
                }
                else
                    one = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                int order = up[i][j];
                order = min(order, down[i][j]);
                order = min(order, right[i][j]);
                order = min(order, left[i][j]);
                ans = max(ans, order);
            }
        }
        return ans;
    }
};
// @lc code=end

