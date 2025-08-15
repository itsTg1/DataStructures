class Solution {
public:
    int findMaxProfit(vector<int>& prices,int i,int isbuy,vector<vector<int>> &dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][isbuy]!=-1){
            return dp[i][isbuy];
        }
        int profit=0;
        int inc=0;
        int exc=0;
        if(isbuy==0){
            int include=((-1)*prices[i]) + findMaxProfit(prices,i+1,1,dp);
            int exclude=findMaxProfit(prices,i+1,0,dp);
            profit+=max(include,exclude);
        }
        else{
            int inc=prices[i] + findMaxProfit(prices,i+1,0,dp);
            int exc=findMaxProfit(prices,i+1,1,dp);
            profit+=max(inc,exc);
        }
        return dp[i][isbuy]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return findMaxProfit(prices,0,0,dp);
    }
};