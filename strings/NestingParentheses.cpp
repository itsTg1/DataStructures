class Solution {
    public:
        int maxDepth(string s) {
            string parenth="";
            for(int i=0;i<s.length();i++){
                if(s[i]=='(' || s[i]==')'){
                    parenth+=s[i];
                }
            }
            int ans=0;
            int i=0;
            stack<char> st;
            while(i<parenth.length()){
                if(parenth[i]=='('){
                    st.push(parenth[i]);
                    i++;
                }
                else if(parenth[i]==')'){
                    int temp=0;
                    while(!st.empty() && parenth[i]==')'){
                        temp++;
                        st.pop();
                        i++;
                    }
                    temp+=st.size();
                    ans=max(ans,temp);
                }
            }   
            return ans;
        }
    };