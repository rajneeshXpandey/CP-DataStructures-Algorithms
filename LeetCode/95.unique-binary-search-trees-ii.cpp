/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
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
class Solution {
public:  
              
    /*
           root     
    1 2 3  (4)  5 6 7 8  
    
    */

    vector<TreeNode *> buildTree(int start, int end)
    {
        vector<TreeNode *> trees;
        //base cases
        if(start>end){
            trees.push_back(nullptr);
            return trees;
        }
        if(start==end) {
            TreeNode *root = new TreeNode(start);
            trees.push_back(root);
            return trees;
        }
        for(int i=start;i<=end;i++){
        vector<TreeNode *> ltrees = buildTree(start,i-1);
        vector<TreeNode *> rtrees = buildTree(i+1,end);
            for(auto lroot : ltrees){
                for(auto rroot : rtrees){
                    TreeNode *root = new TreeNode(i);
                    root->left = lroot;
                    root->right = rroot;
                    trees.push_back(root);
                }
            }
        }

        return trees;

    }
    vector<TreeNode *> generateTrees(int n)
    {
        return buildTree(1,n);
    }
};
// @lc code=end

