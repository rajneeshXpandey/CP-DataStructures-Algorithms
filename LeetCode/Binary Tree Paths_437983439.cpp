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
  vector<string> v;
    vector<string> binaryTreePaths(TreeNode* root) {    
      if(!root)
        return v;
      
    
   dfs(root,"");
      
        
      return v;
      
    }
 

 string dfs(TreeNode* root,string st)
 {     
   
  
   
    if(!root->left and !root->right)
       {
       if(st=="")
     st += to_string(root->val);
   else
   st += "->"+to_string(root->val);
      v.push_back(st);
      return "";
    }       
    
    if(st=="")
     st += to_string(root->val);
   else
   st += "->"+to_string(root->val);
   
   if(root->left)
     dfs(root->left,st);     
    
   if(root->right)
     dfs(root->right,st);
    
   return st;
     
 }
  
  
};
