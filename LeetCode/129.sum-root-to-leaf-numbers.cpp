/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sum = 0;
    void dfs(TreeNode *root, string &temp_sum)
    {
        if (!root->left and !root->right)
        {
            temp_sum += root->val + '0';
            sum += stoi(temp_sum);
            temp_sum.pop_back();
            return;
        }
        temp_sum += root->val + '0';
        if (root->left)
            dfs(root->left, temp_sum);
        if (root->right)
            dfs(root->right, temp_sum);
        temp_sum.pop_back();
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        string str = "";
        dfs(root, str);
        return sum;
    }
};
// @lc code=end

