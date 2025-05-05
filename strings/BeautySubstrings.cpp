class Solution {
    public:
        int beautySum(string s) {
            int ans=0;
            for(int i=0;i<s.length();i++){
                map<char,int> mp;
                mp[s[i]]++;
                for(int j=i+1;j<s.length();j++){
                    mp[s[j]]++;
                    if(mp.size()>1){
                        int mine=INT_MAX;
                        int maxe=INT_MIN;
                        for(auto it:mp){
                            mine=min(mine,it.second);
                            maxe=max(maxe,it.second);
                        }
                        ans+=(maxe-mine);
                        
                    }
                   
                }
            }
            return ans;
        }
    };