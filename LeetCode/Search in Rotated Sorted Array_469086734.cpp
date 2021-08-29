class Solution {
public:
  
int binarySearch(vector<int> arr,int s,int e,int key)
    {
      while(s<=e)
      {
        int mid = (s+e)/2;
        
        if(arr[mid]==key)
           return mid;
        else if(arr[mid]<key)
           s = mid+1;
        else if(arr[mid]>key)
          e = mid-1;         
      }
      return -1;
    }

int search(vector<int>& arr, int target) {
        int n = arr.size();
      
      if(n==1)
        return (arr[0]==target)?0:-1;
      
      
     int s=0, e = n-1;
    int idx = -1;
    while(s<=e)
     {
         int mid = (s+e)/2;
         int left = ((mid-1)+n)%n ;
         int right = (mid+1)%n;
         if(arr[left]>arr[mid] and arr[mid]<arr[right])
          {
              idx = mid;
              break;
          }
          else if(arr[mid]<=arr[e])
             e = mid-1;
           
          else if(arr[mid]>=arr[s])
           s = mid+1;
     }    
      int left = binarySearch(arr,0,idx-1,target);
      int right = binarySearch(arr,idx,n-1,target);
      
      return (left == -1)?right:left;
    }
};
