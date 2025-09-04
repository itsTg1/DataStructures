class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int cnt=0;
        vector<int> tempArr=arr;
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[tempArr[i]]=i;
        }
        for(int i=0;i<arr.size();i++){
            if(tempArr[i]!=arr[i]){
                int idx=mp[arr[i]];
                swap(tempArr[i],tempArr[idx]);
                // bcz after swap elements position is changing so update new position in map
                mp[tempArr[idx]]=idx;
                cnt++;
            }
        }
        return cnt;
    }
};