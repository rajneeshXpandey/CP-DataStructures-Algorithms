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
     // <--------recursive BFS-------->
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    void recursiveBFS(TreeNode* root,int level,vector<int> &lev)
    {
        if(!root) return;
        if(level==0)
            lev.push_back(root->val);
        else
        {
            recursiveBFS(root->left,level-1,lev);
            recursiveBFS(root->right,level-1,lev);
        }  
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
          int h = height(root);
         vector<vector<int>> ans;
        for(int l=h-1;l>=0;l--){
            vector<int> lev;
            recursiveBFS(root,l,lev);
            ans.push_back(lev); 
        }
        
        return ans;
    }
};
