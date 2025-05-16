class Solution {
  public:
    string removeKdigits(string s, int k) {
      
        if(k>=s.length()){
            return "0";
        }
        stack<char> st;
        int i=0;
        while(k>0 && i<s.length()){
            while(k>0 && !st.empty() && (int)s[i]<(int)st.top()){
                st.pop();
                k--;
            }
            st.push(s[i]);
            i++;
        }
        // yahi galti hogi
        while(k>0){
            st.pop();
            k--;
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        
        string toAdd=s.substr(i,s.length()-i);
        temp=temp+toAdd;
        int cnt=0;
        for(int j=0;j<temp.length();j++){
            if(temp[j]!='0'){
                break;
            }
            else{
                cnt++;
            }
        }
        if(cnt==temp.length()){
            return "0";
        }
        return temp.substr(cnt,temp.length()-cnt);
        
    }
};