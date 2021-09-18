/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        if(n>m){
            swap(nums1,nums2);
            swap(n,m);
        }
        for(auto i : nums1){
            freq[i]++;
        }
        for(auto i : nums2){
            if(freq.count(i)){
                ans.push_back(i);
                if(freq[i]==1) freq.erase(i);
                else freq[i]--;
            }
        }
        return ans;
    }
};
// @lc code=end

