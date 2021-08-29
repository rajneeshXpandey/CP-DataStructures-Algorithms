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
     
  bool flag =1;
  TreeNode* t = NULL;
   bool find(TreeNode* root,int x,TreeNode* temp)
   {
     
       bool a=0,b=0;
     
     
     if(root != temp && x==root->val)
          return true;
     
     
    if(root->left)
      a = find(root->left,x,temp);
     if(root->right)
      b = find(root->right,x,temp);
         
    
     return a || b;
       
   }
  
  bool findTarget(TreeNode* root, int k) {
      
      if(!root)
         return false;
    
    bool a=0,b=0;
    
    if(flag)
    {
      flag =0;
      t = root;
    }      
    int x = k - root->val;
      
      
      if(find(t,x,root))
          return true;
    
     if(root->left )  
       a = findTarget(root->left,k);
     if(root->right)
       b = findTarget(root->right,k);  
    
      return a || b;
        
    }
};
