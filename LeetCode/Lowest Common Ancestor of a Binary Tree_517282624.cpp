/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, 
        TreeNode* q) {

        if(!root or root==p or root==q)
            return root;
        
        TreeNode *lnode = lowestCommonAncestor(root->left,p,q);
        TreeNode *rnode = lowestCommonAncestor(root->right,p,q);
        
        if(lnode and rnode)
            return root;
        if(lnode)
            return lnode;
        else
            return rnode;
    }
};
