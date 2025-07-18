

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        stack<int> st;
        int i=0;
        while(i<arr.size()){
            while(!st.empty() && arr[i]>st.top()){
                st.pop();
            }
            st.push(arr[i]);
            i++;
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};