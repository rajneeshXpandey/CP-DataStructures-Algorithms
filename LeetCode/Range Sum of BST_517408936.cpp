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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(!root) return 0;
        
        int sum1=0,sum2=0,sum3=0;
        
    if(root->val<low)
     sum1 = rangeSumBST(root->right,low,high);
    else if(root->val>high)
     sum2 = rangeSumBST(root->left,low,high);
    else 
     sum3 = root->val+rangeSumBST(root->right,low,high)+rangeSumBST
         (root->left,low,high);

    return sum1+sum2+sum3;
    }
};
