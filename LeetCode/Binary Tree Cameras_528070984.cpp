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
    int camera=0;
    /**
    states 1 (have camera) : 0  : node have cameras
           2 (no camera)   : 1  : covered
                           : -1 : need to cover 
                           
    base case : if(!root) return 1;
    
    special case : cover(root) = -1 : then camera++;
    */
    int cover(TreeNode* root){
        if(!root) return 1;
        int leftCover = cover(root->left);
        int rightCover = cover(root->right);
        
        if(leftCover==-1 or rightCover==-1){
            camera++;
            return 0;
        }
        if(leftCover==0 or rightCover==0) return 1;
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
      
      int rootNeed = cover(root);
      if(rootNeed==-1) camera++;
        
      return camera;  
    }
};
