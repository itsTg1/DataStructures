class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minn=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minn){
                minn=prices[i];
            }
            else if(prices[i]>minn){
                profit=max(profit,prices[i]-minn);
            }
        }
        return profit;
    }
};