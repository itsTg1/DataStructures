class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int LIS=1;
        int n=arr.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    LIS=max(LIS,dp[i]);
                }
            }
        }
        return LIS;
    }
};