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
    vector<int> rightV;
    int maxLevel=-1;
    void rightView(TreeNode* root,int level){
        if(!root)
             return;
        if(maxLevel<level){
            rightV.push_back(root->val);
            maxLevel = level;
        }
        
        rightView(root->right,level+1);
        rightView(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
             return {};
        rightView(root,0);
        return rightV;
    }
};
