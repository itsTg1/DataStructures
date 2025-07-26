https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1



class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0;
        int j=0;
        int ans=INT_MIN;
        int cnt=0;
        while(i<arr.size() && j<arr.size()){
            if(arr[i] <= dep[j]){
                cnt++;
                ans=max(cnt,ans);
                i++;
            }
            if(dep[j]<arr[i]){
                cnt--;
                j++;
            }
        }
        return ans;
    }
};
