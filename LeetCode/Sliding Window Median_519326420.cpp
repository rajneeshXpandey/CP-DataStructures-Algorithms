class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> st(nums.begin(), nums.begin() + k);
        auto mid = next(st.begin(),k/2);
        int j=k;
        while(1){ 
            ans.push_back((double(*mid) + *prev(mid,1-k%2))/2);
            if(j==nums.size())
                return ans;
            st.insert(nums[j]);
            if(nums[j] < *mid)
                mid--;
            if(nums[j-k] <= *mid)
                mid++;
            st.erase(st.lower_bound(nums[j-k]));
            j++;    
        }  
    }
};
