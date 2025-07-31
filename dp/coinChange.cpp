class Solution {
public:
 
    int makeAmount(vector<int>& coins, int amount, int idx,vector<vector<int>> &dp) {
        if(idx==0){
            if((amount%coins[0])==0){
                return amount/coins[idx];
            }
            return 1e+9;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int notake=makeAmount(coins,amount,idx-1,dp);
        int take=INT_MAX;
        if(coins[idx]<=amount){
            take=1+makeAmount(coins,amount-coins[idx],idx,dp);
        }
        return dp[idx][amount]=min(take,notake);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int idx=coins.size()-1;
        int ans=makeAmount(coins,amount,idx,dp);
        if(ans<1e+9){
            return ans;
        }
        return -1;
    }
};