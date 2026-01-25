class Solution {
public:
    int countPaths(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return INT_MIN;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int option1=0;
        
        int option2=0;
        option1+=countPaths(m,n,i,j+1,dp);
        option2+=countPaths(m,n,i+1,j,dp);
        if(option1>0 && option2>0){
            return dp[i][j]=option1+option2;
        }
        else if(option1>0){
            return dp[i][j]=option1;
        }
        else if(option2>0){
            return dp[i][j]=option2;
        }
        return dp[i][j]=INT_MIN;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countPaths(m,n,0,0,dp);
    }
};