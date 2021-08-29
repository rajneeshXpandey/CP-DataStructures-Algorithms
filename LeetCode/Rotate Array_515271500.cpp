class Solution {
public:
    
    void rot(vector<int>& nums, int l,int r)
    {
     int i=l,j=r;
     while(i<j)
     {
         swap(nums[i],nums[j]);
         i++;j--;
     }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k<=0) return;
        //if(k<0) then k = k+n
  // <-------- Reversal Algorithm------->      
        rot(nums,0,n-k-1);
        rot(nums,n-k,n-1);
        
        rot(nums,0,n-1);
        
        
    }
};
