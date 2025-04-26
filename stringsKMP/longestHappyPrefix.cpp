class Solution {
    public:
        string longestPrefix(string s) {
            int n=s.length();
            vector<int> len(n);
            int pref=0;
            int suffix=1;
            len[0]=0;
            while(suffix<n){
                if(s[pref]==s[suffix]){
                    pref++;
                    len[suffix]=pref;
                    suffix++;
                }
                else
                {
                    if(pref==0){
                        len[suffix]=pref;
                        suffix++;
                    }
                    else{
                        pref=len[pref-1];
                    }
                }
            }
    
            int cnt=len.back();
            string ans="";
            int j=0;
            while(cnt--){
                ans+=s[j];
                j++;
            }
            return ans;
    
        }
    };