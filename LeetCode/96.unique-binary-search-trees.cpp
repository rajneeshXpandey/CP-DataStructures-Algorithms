/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
/*
 1 2 3 
*/
    int numTrees(int n) {
      vector<int> dp(n+1,1);
      for(int node=2;node<=n;node++)
       {   
           int total = 0; // upto "node"
           for(int root=1;root<=node;root++)
            {
                int left = root-1;
                int right = node-root;
                total += dp[left] * dp[right];
            }
            dp[node] = total;
        }
        return dp[n];
    }
};
// @lc code=end

