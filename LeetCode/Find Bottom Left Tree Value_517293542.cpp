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
    vector<int> leftV;
    int maxLevel=-1;
    void leftView(TreeNode* root,int level){
        if(!root)
             return;
        if(maxLevel<level){
            leftV.push_back(root->val);
            maxLevel = level;
        }
        
        leftView(root->left,level+1); 
        leftView(root->right,level+1);
      
    }
    int findBottomLeftValue(TreeNode* root) {
        
        // can also be done using BFS
        leftView(root,0);
        return leftV.back();
    }
};
