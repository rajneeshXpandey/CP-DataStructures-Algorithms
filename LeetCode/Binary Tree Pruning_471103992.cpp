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
  
   bool allzero(TreeNode* root){
      
     if(root->val==1) return false;
     
      if(!root->left and !root->right) 
      return (root->val==0)?true:false;
     
     
     if(root->left and !root->right)
      { bool l = allzero(root->left);
        return l and (root->val==0);
          }
    else if(root->right and !root->left)
      { bool r = allzero(root->right);
        return r and (root->val==0);
       }
     else if(root->right and root->left)
     {
         bool r = allzero(root->right);     
          bool l = allzero(root->left);
       return (r and l and (root->val==0));
     }
    return false;
   }
   
    TreeNode* pruneTree(TreeNode* root) {
        
      if(!root) return root;
      
         if(!root->left and !root->right) 
            return (root->val==1)?root:NULL;

       if(allzero(root)) return NULL;

       root->left =  pruneTree(root->left);
       root->right = pruneTree(root->right);
      
        return root;
           
    }
};
