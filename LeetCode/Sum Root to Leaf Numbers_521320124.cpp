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
    int ans = 0;
    string s = "";
    int mod = 1003;
    int sumNumbers(TreeNode* root) {
        
     if(root!=NULL && root->left==NULL && root->right==NULL){
        s += to_string(root->val);
        ans = (ans+stoi(s));
        // cout<<s<<" "; 
        s.pop_back();
        return ans;
    } 

    s += to_string(root->val);
    if(root->left!=NULL)
        sumNumbers(root->left);
    if(root->right!=NULL)
        sumNumbers(root->right);
    s.pop_back();

    return ans;
    }
};
