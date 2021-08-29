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
    
    void recursiveBFS(TreeNode* root,int level,vector<int> &lev,bool 
        flip)
    {
        if(!root) return;
        if(level==0)
            lev.push_back(root->val);
        else
        {
            if(!flip){
                recursiveBFS(root->left,level-1,lev,flip);
                recursiveBFS(root->right,level-1,lev,flip);
            }
            else {
                recursiveBFS(root->right,level-1,lev,flip);
                recursiveBFS(root->left,level-1,lev,flip);
            }
        }  
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        bool flip = 0;
        for(int l=0;l<h;l++){
            vector<int> lev;
            recursiveBFS(root,l,lev,flip);
            flip = !(flip);
            ans.push_back(lev); 
        }
        
        return ans;
    }
};
