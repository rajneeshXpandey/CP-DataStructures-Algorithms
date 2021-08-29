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
 unordered_map<int, int> mp;
    int max = -1;
public:
    void preorder(TreeNode *root){
        if(!root)
            return;
        int val = ++mp[root->val];
        if(val>max)
            max=val;
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        preorder(root);
        for(auto it: mp){
            if(it.second==max)
                ans.push_back(it.first);
        }
        return ans;
    }
};
