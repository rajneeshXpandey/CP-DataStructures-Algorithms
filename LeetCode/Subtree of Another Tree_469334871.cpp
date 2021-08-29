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
 
   bool check(TreeNode* s, TreeNode* t)
   {
        if(t==NULL and s==NULL)
         return true;
     
      if(t==NULL || s==NULL)
         return false;
     
     if(s->val != t->val)
        return false;


       return (check(s->left,t->left) && check(s->right,t->right));

   }
     
    bool isSubtree(TreeNode* s, TreeNode* t) {
   
       if(s==NULL) return false;
       if(check(s,t)) return true;  
      return (isSubtree(s->left,t) || isSubtree(s->right,t));
    }
};
