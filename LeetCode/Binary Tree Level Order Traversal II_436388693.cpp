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
  
 vector<vector<int>> levelOrderBottom(TreeNode* root) {
       
      vector<vector<int> > v;
      
      if(root == NULL)
          return v;
      
    
      
      queue<TreeNode*> q;
           
      
      q.push(root);
      
      vector<int> temp = {root->val};
     v.push_back(temp);
   
      while(!q.empty())
      {  
        int size=q.size();
        
        vector<int> subv;
        
        while(size--)
      {
          TreeNode* temp = q.front(); 
          
          q.pop();   
          
          
      if(temp->left)
         { 
           q.push(temp->left);
           subv.push_back(temp->left->val);
         }         
           if(temp->right)
          {  
             q.push(temp->right);          
             subv.push_back(temp->right->val);
             
           }          
         } 
        if(subv.size())
            v.push_back(subv);

  }
   
   reverse(v.begin(),v.end());
   
      return v;
    }
};
