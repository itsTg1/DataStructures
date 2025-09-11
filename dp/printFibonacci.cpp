int printFibonacci(int n,vector<int> &dp){
    if(n==0){
        
        return 0;
    }
    if(n==1){
        
        return 1;
    }
    if(dp[n]!=-1){
       
        return dp[n];
    }
    int ans=printFibonacci(n-1,dp)+printFibonacci(n-2,dp);
    cout<<ans<<" ";
    return dp[n]=ans;
}

int main() {
    cout<<0<<" ";
    cout<<1<<" ";
    vector<int> dp(n+1,-1); 
    printFibonacci(n,dp);

}