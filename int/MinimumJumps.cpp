class Solution {
  public:
    int findMinJumps(vector<int> &arr,int i,int n,vector<int> &dp){
        if(i>=(n-1)){
            return 0;
        }
        if(arr[i]==0){
            return 1e+9;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int j=1;j<=arr[i];j++){
            int curr=1+findMinJumps(arr,i+j,n,dp);
            ans=min(ans,curr);
        }
        return dp[i]=ans;
    }
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n+100,-1);
        int ans=findMinJumps(arr,0,n,dp);
        
        if(ans<1e+9){
            return ans;
        }
        return -1;
    }
};
