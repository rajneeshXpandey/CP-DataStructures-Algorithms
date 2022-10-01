/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
/*boundary dfs*/
class Solution
{
public:
    vector<vector<int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pair<int, int>> points;
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visi, int x, int y)
    {
        if (x < 0 or x > board.size() - 1 or y < 0 or y > board[0].size() - 1 or board[x][y] == 'X' or visi[x][y])
            return;
        visi[x][y] = 1;
        points.push_back({x, y});
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dxy[i][0], yy = y + dxy[i][1];
            dfs(board, visi, xx, yy);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        vector<vector<bool>> visi(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (i == 0 or i == board.size() - 1 or j == 0 or j == board[0].size() - 1 and board[i][j] == 'O' and !visi[i][j])
                    dfs(board, visi, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = 'X';
            }
        }
        for (auto pts : points)
        {
            board[pts.first][pts.second] = 'O';
        }
    }
};
// @lc code=end

