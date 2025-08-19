// leet 921

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }
        ans=ans+st.size();
        return ans;
    }
};