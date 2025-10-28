class Solution {
  public:
    string decodedString(string &s) {
        // code here

        stack<string> st;
        string ans="";
        string tem="";
        for(int i=s.length()-1;i>=0;){
            
            if(s[i]=='['){
                while(!st.empty() && st.top()!="]"){
                    tem+=st.top();
                    st.pop();
                }
                st.pop();
                i--;
            }
            else if(s[i]>='0' && s[i]<='9'){
                string num="";
                while(i>=0 && s[i]>='0' && s[i]<='9'){
                    num+=s[i];
                    i--;
                }
                reverse(num.begin(),num.end());
                int n=stoi(num);
                n-=1;
                string result=tem;
                while(n--){
                    result+=tem;
                }
              
                if(!st.empty()){
                    st.push(result);
                }
                else{
                    ans=result+ans;
                }
                tem="";
            }
            else{
                string topush="";
                topush+=s[i];
                st.push(topush);
                i--;
            }
        }
        return ans;
    }
};