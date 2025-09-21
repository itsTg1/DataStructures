class Solution {
  public:
   
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        map<int,int> mp;
        sort(greed.begin(),greed.end());
        int cnt=0;
        for(int i=0;i<cookie.size();i++){
            mp[cookie[i]]++;
        }
        for(int i=0;i<greed.size();i++){
            int curr=greed[i];
            for(auto it:mp){
                if(it.first>=curr){
                    mp[it.first]--;
                    if(mp[it.first]==0){
                        mp.erase(it.first);
                    }
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};