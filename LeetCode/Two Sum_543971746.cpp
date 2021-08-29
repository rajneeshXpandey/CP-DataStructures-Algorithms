class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> with_i;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            with_i.push_back({nums[i],i});
        }
        sort(with_i.begin(),with_i.end());
        int i=0,j=n-1;
        while(i<=j){
            if(with_i[i].first + with_i[j].first == target)
                return {with_i[i].second,with_i[j].second};
            else if(with_i[i].first+with_i[j].first>target)
                 j--;
            else
                 i++;
        }
     return {};
    } 
};
