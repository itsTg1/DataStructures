class Solution {
public:
    string smallestSubsequence(string s) {
        vector<char> v;
        int n=s.length();
        vector<int> lstIdx(26);
        vector<bool> isUsed(26,0);
        for(int i=0;i<n;i++){
            lstIdx[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++){
            while(v.size()>0 && v.back()>s[i] && lstIdx[v.back()-'a']>i && !isUsed[s[i]-'a']){
                isUsed[v.back()-'a']=0;
                v.pop_back();
                
            }
            if(!isUsed[s[i]-'a']){
                v.push_back(s[i]);
                isUsed[s[i]-'a']=1;
            }
            
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
        return ans;
    }
};