class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int L=1;L<=s.length();L++){
            for(int i=0;(i+L-1)<n;i++){
                int j=i+L-1;
                if(j-i+1==1){
                    dp[i][j]=true;
                }
                else if(j-i+1==2){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=((s[i]==s[j]) && (dp[i+1][j-1]));
                }
                if(dp[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};