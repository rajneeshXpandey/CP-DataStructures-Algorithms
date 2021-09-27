/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> obst(n, vector<int>(m, -1));

        queue<vector<int>> q;
        q.push({0, 0, k, 0}); // i , j , k , dis

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto curr = q.front();
                q.pop();

                if (curr[0] == n - 1 and curr[1] == m - 1)
                    return curr[3];

                if (grid[curr[0]][curr[1]] == 1)
                    curr[2]--;

                for (int dir = 0; dir < 4; dir++)
                {
                    int x = curr[0] + dx[dir];
                    int y = curr[1] + dy[dir];
                    if (x >= 0 and x < n and y >= 0 and y < m and obst[x][y] < curr[2])
                    {
                        q.push({x, y, curr[2], curr[3] + 1});
                        obst[x][y] = curr[2];
                    }
                }
            }
        }
        return -1;
    }
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int ans = bfs(grid, k);
        return ans;
    }
};
// @lc code=end

