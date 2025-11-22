class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> nextSmallest(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                nextSmallest[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return nextSmallest;
    }
};