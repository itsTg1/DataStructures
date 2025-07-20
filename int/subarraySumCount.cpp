// leetcode 560

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int i=0;
        int cnt=0;
        int sum=0;
        while(i<arr.size()){
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            
            mp[sum]++;
           
            i++;
        }
        return cnt;
    }

};