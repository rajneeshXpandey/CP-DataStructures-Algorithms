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
    bool search(TreeNode* root,int tar,int k){
        if(!root) return false;
        if(root->val==tar and root->val!=k-tar)
             return true;
        if(root->val > tar)
         return search(root->left,tar,k);
        else if(root->val < tar)   
         return search(root->right,tar,k);
        return false;
    }
    bool dfs(TreeNode* head,TreeNode* root, int k){
        if(!root) return false;
    return (search(head,k-(root->val),k)) || dfs(head,root->left, k) 
        || dfs(head,root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        return dfs(root,root,k);
    }
};
