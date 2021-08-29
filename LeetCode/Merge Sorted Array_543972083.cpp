class Solution {
public:
    //this can also be done in backward direction 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0,j=0;
      
       while(i<(m+n) and j<n)
       {
         if(nums1[i]<=nums2[j])
           i++;
         else if(nums1[i]>nums2[j])
         {           
           for(int k = (m+n)-1;k>=i+1;k--)
             nums1[k]=nums1[k-1];             
           nums1[i]=nums2[j];
           j++;
           i++;
         }
       }
      i=n-j;
      i = (m+n)-i;

      while(i<(m+n) and j<n)
      {
        nums1[i]=nums2[j];
        i++;
        j++;
      }
    }
};
