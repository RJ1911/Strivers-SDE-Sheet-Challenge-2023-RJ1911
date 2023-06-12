class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int maxProfit = 0;
        int minprice = INT_MAX;
        int profit = 0;
        for(int i = 0 ; i < n ;i++)
        {
            minprice = min(prices[i],minprice);
            profit = max(profit,prices[i] - minprice);
            // for(int j = i+1; j < n ;j++)
            // {
            //     int profit = prices[j] - prices[i];
            //     cout<<prices[i]<<" "<<prices[j]<<" = "<<profit<<endl;
            //     maxProfit = max(profit,maxProfit);
            // }
        }
        
        return profit;
    }
};
