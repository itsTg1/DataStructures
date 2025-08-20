
// User function template for C++

class Solution {
    public:
      bool checkPallindrome(string st,int s,int e,vector<vector<int>> &dp){
          if(s>=e){
              return true;
          }
          if(dp[s][e]!=-1){
              return dp[s][e];
          }
          if(st[s]==st[e]){
              return dp[s][e]=checkPallindrome(st,s+1,e-1,dp);
          }
          return false;
      }
      string longestPalindrome(string s) {
          // code here
          string ans="";
          int n=s.length();
          vector<vector<int>> dp(n,vector<int>(n,-1));
          int maxlen=0;
          for(int i=0;i<s.length();i++){
              for(int j=i;j<s.length();j++){
                  bool anss=checkPallindrome(s,i,j,dp);
                  if(anss && j-i+1>maxlen){
                      maxlen=j-i+1;
                      ans=s.substr(i,j-i+1);
                  }
              }
          }
          return ans;
      }
  };


//   ----------------------------------BOTTOM UP APPROACH---------------------

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
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
                if(dp[i][j]==1 && (j-i+1)>ans.length()){
                    ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};