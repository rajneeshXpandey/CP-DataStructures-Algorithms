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
    bool isSymmetric(TreeNode* root) {
      
      
      return symm(root,root); 
      
    }
  
  bool symm(TreeNode* l,TreeNode* r)
  {  
   
    if(l == NULL && r == NULL)
      return true;
    
    if(l == NULL || r == NULL)
      return false;
        
    
    return ((l->val == r->val) and symm(l->right,r->left) and symm(l
        ->left,r->right)) ;
  }
};
