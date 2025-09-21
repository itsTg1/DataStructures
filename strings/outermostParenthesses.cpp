class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans="";
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' && count==0){
                count++;
            }
            else if(s[i]==')' && count==1){
                count-=1;
            }
            else if(s[i]=='(' && count>=1){
                ans+=s[i];
                count++;
            }
            else if(s[i]==')' && count>1){
                ans+=s[i];
                count--;
            }
            
        }
        return ans;
    }
};