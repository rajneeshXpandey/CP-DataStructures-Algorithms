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
  
  int ans = INT_MAX;
  int prev = -1; 
  
  void util(TreeNode* root){
     
     if(root->left)
       util(root->left);
     
     if(prev != -1 and ans > (root->val-prev))
         ans  = root->val-prev;
     
     prev = root->val;
     
     if(root->right)
       util(root->right);
     
   
   }
  
    int getMinimumDifference(TreeNode* root) {
      
      if(!root)
        return 0;
      
      util(root);
      
      return ans;
      
    }
};
