/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left
     (left), right(right) {}
 * };
 */
class Solution {
public:
    void bstGst(TreeNode* root,int &prevSum)
    {
        if(!root) return;
        bstGst(root->right,prevSum);
        root->val += prevSum;
        prevSum = root->val;
        bstGst(root->left,prevSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return NULL;
        int prevSum = 0;
        bstGst(root,prevSum);
        return root;
    }
};
