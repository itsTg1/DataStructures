// zero sum subarray count

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int i=0;
        int cnt=0;
        while(i<arr.size()){
            sum+=arr[i];
         
            if(mp.find(sum)!=mp.end()){
                cnt+=mp[sum];
            }
            mp[sum]++;
            i++;
        }
        return cnt;
        
    }
};