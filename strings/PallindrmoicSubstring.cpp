
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