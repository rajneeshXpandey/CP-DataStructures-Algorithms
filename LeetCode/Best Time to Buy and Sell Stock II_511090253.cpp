class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int prof = 0;
        int n = prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i-1]<prices[i])
            {
                int buy = prices[i-1];
                while(i<n and prices[i-1]<prices[i])
                    i++;
                prof += prices[i-1]-buy;
            }
        }
    return prof;
    }
};
