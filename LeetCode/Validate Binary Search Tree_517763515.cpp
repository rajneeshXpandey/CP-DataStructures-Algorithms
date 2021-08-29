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
    bool check(TreeNode* root,long mini,long maxa){
        
      if(!root)
            return true;  
return root->val>mini && root->val<maxa && check(root->left,mini,root
    ->val) && check(root->right,root->val,maxa);
    }
bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        // if(!root->left and !root->right)
        //     return true;
        
        return check(root,LONG_MIN,LONG_MAX);
    }
};
