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
    int sumOfLeftLeaves(TreeNode* root) {
      
       if(!root)
         return 0;
      
       queue<TreeNode*> q;
      
       q.push(root);
      
       queue<bool> lr;
      
       lr.push(0);
      
       int sum=0;
       while(!q.empty())
       {
         
         int size = q.size();

         for(int i=0;i<size;i++)
         {
           TreeNode* temp = q.front();
           bool val = lr.front();
           
           lr.pop();
           
            q.pop();
           
           if(temp->left == NULL && temp->right == NULL && val)
             {
              sum = sum+temp->val;              
             }
         
           
          if(temp->left)
         {  q.push(temp->left);
           lr.push(1);
         }
          if(temp->right)
           { q.push(temp->right);  
             lr.push(0);
           }           
         }
       }
      
      return sum;
        
    }
};
