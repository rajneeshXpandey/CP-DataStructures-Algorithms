class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        int ans = 0;
        vector<int> dp(n, 0);
        int i = 0;
        
        sort(cuboids.begin(), cuboids.end(), [](auto &a, auto &b){
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        });
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
            dp[i] = c.back();
            ++i;
        }
        //finding LIS
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                auto &c2 = cuboids[j];
                auto &c1 = cuboids[i];
                if(c1[0] >= c2[0] && c1[1] >= c2[1] && c1[2] >= c2[2]) 
                    {
                    dp[i] = max(dp[i], dp[j] + max({ cuboids[i][0], 
                        cuboids[i][1], cuboids[i][2] } ));
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
