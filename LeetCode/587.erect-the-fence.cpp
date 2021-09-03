/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution {
public:
    /* Jarvis Algorithm */
    struct point
    {
        int x, y;
    };

    bool cw(point a, point b, point c)
    {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
    }

    bool ccw(point a, point b, point c)
    {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
    }

    void convex_hull(vector<point> &a)
    {
        if (a.size() == 1)
            return;

        sort(a.begin(), a.end(), [](point a, point b)
             { return a.x < b.x || (a.x == b.x && a.y < b.y); });
        point p1 = a[0], p2 = a.back();
        vector<point> up, down;
        up.push_back(p1);
        down.push_back(p1);
        for (int i = 1; i < (int)a.size(); i++)
        {
            if (i == a.size() - 1 || cw(p1, a[i], p2))
            {
                while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                    up.pop_back();
                up.push_back(a[i]);
            }
            if (i == a.size() - 1 || ccw(p1, a[i], p2))
            {
                while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                    down.pop_back();
                down.push_back(a[i]);
            }
        }

        a.clear();
        for (int i = 0; i < (int)up.size(); i++)
            a.push_back(up[i]);
        for (int i = down.size() - 2; i > 0; i--)
            a.push_back(down[i]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {

        int n = trees.size();
        set<vector<int>> anss;
        vector<point> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].x = trees[i][0];
            a[i].y = trees[i][1];
        }
        convex_hull(a);
        n = a.size();
        for (int i = 0; i < n; i++)
        {
            anss.insert({a[i].x, a[i].y});
        }
        vector<vector<int>> ans;
        for (auto pt : anss)
        {
            ans.push_back(pt);
        }
        return ans;
    }
};
// @lc code=end

