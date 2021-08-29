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
        
        TreeNode *llca = lowestCommonAncestor(root->left,p,q);
        TreeNode *rlca = lowestCommonAncestor(root->right,p,q);
        
        if(llca and rlca)
            return root;
        // case of single sided
        if(llca)
            return llca;
        else
            return rlca;
    }
};
