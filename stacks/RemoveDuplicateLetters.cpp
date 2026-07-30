class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastTaken(26);
        vector<bool> isPresent(26,0);
        for(int i=0;i<s.length();i++){
            lastTaken[s[i]-'a']=i;
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(isPresent[s[i]-'a']==1){
                continue;
            }
            while(ans.length()>0 && ans.back()>s[i] && lastTaken[ans.back()-'a']>i){
                isPresent[ans.back()-'a']=0;
                ans.pop_back();
                
            }
            ans.push_back(s[i]);

            isPresent[s[i]-'a']=1;
        }
        return ans;

    }
};