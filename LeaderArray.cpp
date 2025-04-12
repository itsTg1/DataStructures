
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n=arr.size();
        vector<int> largest(n);
        largest[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            largest[i]=max(largest[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==largest[i]){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};