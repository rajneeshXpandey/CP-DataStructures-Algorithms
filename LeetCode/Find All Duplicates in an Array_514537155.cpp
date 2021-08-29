class Solution {
public:
    
    // O(N) and O(1)  using swapSort
    
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        int i=0;
        int n = arr.size();
        while(i<n)
        {
            if(arr[i]!=arr[arr[i]-1])
                 swap(arr[i],arr[arr[i]-1]);
            else 
                i++;
        }
        for(int i=0;i<n;i++)
        {
           if(arr[i]!=i+1)
                ans.push_back(arr[i]);
        }
        
        return ans;
    }
};
