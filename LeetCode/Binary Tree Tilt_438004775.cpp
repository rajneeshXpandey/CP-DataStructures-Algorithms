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
  int sum = 0;
  int tiltsum(TreeNode* root)
  {
    
    if(!root)
      return 0;
     
      
     
       int left = tiltsum(root->left);
     
       
       int right =  tiltsum(root->right);
    
       int tilt = abs(left-right);
      
       sum += tilt;
    
    return root->val+left+right;
    
  
  }
  
    int findTilt(TreeNode* root) {
      
        if(!root)
          return 0;
      tiltsum(root);
      
    return  sum;
              }
};
