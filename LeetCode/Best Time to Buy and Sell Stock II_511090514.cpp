class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int prof = 0;
        int n = prices.size();
        for(int i=0;i<n-1;i++)
        {
            if(prices[i]<prices[i+1])
            {
                int buy = prices[i];
                while(i<n-1 and prices[i]<prices[i+1])
                    i++;
                prof += prices[i]-buy;
            }
        }
    return prof;
    }
    
 };
