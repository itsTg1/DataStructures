// User function Template for C++

class Solution {
  public:
    int countAll(int N,int M,int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i>=N || j>=M || matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=countAll(N,M,i,j+1,matrix,dp);
        int down=countAll(N,M,i+1,j,matrix,dp);
        int diag=countAll(N,M,i+1,j+1,matrix,dp);
        
        return dp[i][j]=1+min({right,down,diag});
        
        
         
        
    }
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        vector<vector<int>> dp(N,vector<int>(M,-1));
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                ans+=countAll(N,M,i,j,matrix,dp);
            }
        }
        return ans;
    }
};
