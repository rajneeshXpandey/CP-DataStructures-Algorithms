class Solution {
public:
    vector<vector<int>> ans;
    void permutation(vector<int> &nums,int i,int n)
    {
        if(i==n)
            {
                vector<int> vec;
               for(int i=0;i<nums.size();i++)
                   vec.push_back(nums[i]);
                ans.push_back(vec);
                return;
            }
        for(int k=i;k<=n;k++)
            {
                swap(nums[k],nums[i]);
                permutation(nums,i+1,n);
                swap(nums[k],nums[i]);
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        permutation(nums,0,n-1);
        return ans;
    }
};
