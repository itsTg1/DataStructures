class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        vector<int> ans(n,-1);
        int i=n-1;
        stack<int> st;
        while(i>=0){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=i-ans[i];
        }
        return ans;
    }
};