class Solution {
  public:
    
    int findMaxvalue(int W,vector<int> &val,vector<int> &wt,int i,vector<vector<int>> &dp){
        if(i>=val.size()){
            return 0;
        }
        if(W==0){
            return 0;
        }
        if(dp[W][i]!=-1){
            return dp[W][i];
        }
        int include=0;
        if(W>=wt[i]){
            include=val[i]+findMaxvalue(W-wt[i],val,wt,i+1,dp);
        }
        int exclude=0+findMaxvalue(W,val,wt,i+1,dp);
        return dp[W][i]=max(exclude,include);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        if(W==0){
            return 0;
        }
        int n=val.size();
        vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
        return findMaxvalue(W,val,wt,0,dp);
    }
};