class Solution {
  public:
    vector<int> greatLeft(vector<int> & arr){
        vector<int> ans(arr.size());
        ans[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            ans[i]=max(arr[i],ans[i-1]);
        }
        return ans;
    }
    vector<int> greatRight(vector<int> &arr){
        vector<int> ans(arr.size());
        ans[arr.size()-1]=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            ans[i]=max(arr[i],ans[i+1]);
        }
        return ans;
    }
    int maxWater(vector<int> &arr) {
        // code here
        int ans=0;
        vector<int> greatestLeft=greatLeft(arr);
        vector<int> greatestRight=greatRight(arr);
        for(int i=0;i<arr.size();i++){
            ans+=min(greatestLeft[i],greatestRight[i]) - arr[i];
        }
        return ans;
    }
};