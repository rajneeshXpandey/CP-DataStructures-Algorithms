class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
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
                ans.push_back(i+1);
        }
        
        return ans;
    }
};

