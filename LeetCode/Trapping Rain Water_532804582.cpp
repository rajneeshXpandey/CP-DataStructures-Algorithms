class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n==0) return {};
        
        vector<int> maxL(n), maxR(n);
        
        maxL[0] = height[0];
        
        for(int i=1;i<n;i++){
            maxL[i] = max(maxL[i-1],height[i]); 
        }
        
        maxR[n-1] = height[n-1];
        
        for(int i=n-2;i>=0;i--){
            maxR[i] = max(maxR[i+1],height[i]); 
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            // cout<<(min(maxR[i],maxL[i])-height[i])<<' ';
            ans += (min(maxR[i],maxL[i])-height[i]); 
        }
        return ans;
    }
};
