// 560


class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
  
        int i=0;
        
        int longest=0;
        int prefSum=0;
        
        unordered_map<int,int> mp;
        mp[0]=1;
        while(i<arr.size()){
            prefSum+=arr[i];
            if(mp.find(prefSum-k)!=mp.end()){
                longest+=mp[prefSum-k];

            }
            
            mp[prefSum]++;
           
            i++;
        }
        return longest;
    }

};