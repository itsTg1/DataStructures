class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        mp[0]=-1;
        int i=0;
        int len=0;
        int prefSum=0;
        while(i<arr.size()){
            prefSum+=arr[i];
            int toFind=(prefSum);
            if(mp.find(toFind)!=mp.end()){
                len=max(len,i-mp[toFind]);
                
            }
            else if(mp.find(toFind)==mp.end()){
                mp[prefSum]=i;
                
            }
            i++;
            
        }
        return len;
    }
};