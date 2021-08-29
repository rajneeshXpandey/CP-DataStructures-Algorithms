class Solution {
public:
  
int maxSum(vector<int> &arr,int l,int r)
    {
        //base
        if(r==l)
             return arr[l];
        
        //Divide
        int mid = (l+r)/2;
        // left sum
        int lsum = maxSum(arr,l,mid);
        // right sum
        int rsum = maxSum(arr,mid+1,r);
        
    // cross sum
        //    case 1: l to mid
        int s = 0;
        int lcsum=INT_MIN; 
         for(int i=mid;i>=l;i--)
         {
             s += arr[i];
             lcsum = max(s,lcsum);
         } 
        //    case 2: mid to r 
        int rcsum=INT_MIN;
         s = 0;
         for(int i=mid+1;i<=r;i++)
         {
             s += arr[i];
             rcsum = max(s,rcsum);
         }
        
       // this is important 
       int crossSum = max(lcsum+rcsum,max(lcsum,rcsum));
             
       return max(max(lsum,rsum),crossSum);
    }
 
    int maxSubArray(vector<int>& nums) {
          int n = nums.size();
 //<----------------------- Kadane's Algorithm ------------------>
      
        
        int maxSum = nums[0];
        int currSum = 0;
        
        for(int i=0;i<n;i++)
        {
            currSum += nums[i];
            maxSum = max(maxSum,currSum);
            
            if(currSum<=0)
                currSum = 0;
        }
        
        return maxSum;   
        
// <----------------------- Divide&Conquer Algorithm 
    ------------------>
//         return maxSum(nums,0,n-1);
    }
};
