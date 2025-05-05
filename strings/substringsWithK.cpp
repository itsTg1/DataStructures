// gfg-https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/0
// User function template for C++

class Solution {
    public:
      int countSubstr(string& s, int k) {
          // code here.
          map<char,int> mp;
          int i=0;
          int j=0;
          int ans=0;
          while(j<s.length()){
              mp[s[j]]++;
              while(i<=j && mp.size()==k){
                  ans+=(s.length()-j);
                  mp[s[i]]--;
                  if(mp[s[i]]==0){
                      mp.erase(s[i]);
                  }
                  i++;
              }
              j++;
          }
          i=0;
          j=0;
          mp.clear();
          int ans1=0;
          while(j<s.length()){
              mp[s[j]]++;
              while(i<=j && mp.size()==k+1){
                  ans1+=(s.length()-j);
                  mp[s[i]]--;
                  if(mp[s[i]]==0){
                      mp.erase(s[i]);
                  }
                  i++;
              }
              j++;
          }
          
          return ans-ans1;
      }
  };