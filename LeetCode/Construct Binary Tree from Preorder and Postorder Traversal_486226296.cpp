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
    TreeNode* tree(vector<int>& pre, vector<int>& post,int st,int stpo
        ,int end)
    {
       if(end==0)
         return nullptr;
      
      TreeNode* root = new TreeNode(pre[st]);
      
      if(end==1)
        return root;
      
        int cut = 1;
        for (; cut < end; ++cut)
            if (post[cut+stpo-1] == pre[st+1])
                break;
      
       root->left  =  tree(pre,post,st+1,stpo,cut);
  //size will reduce
       root->right =  tree(pre,post,st+cut+1,stpo+cut,end-cut-1);
      
      return root;
      
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post
        ) {
      
      int n = pre.size();
     return tree(pre,post,0,0,n);
      
    }
};
