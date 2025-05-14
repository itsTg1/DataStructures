class Solution {
public:
    vector<int> findSmallerLeft(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        return ans;
    }
    vector<int> findSmallerRight(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        int i=0;
        while(i<n){
            while(!st.empty() && arr[st.top()]>arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> smallerLeft=findSmallerLeft(arr);
        vector<int> smallerRight=findSmallerRight(arr);
        long long ans = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - smallerLeft[i];
            long long right = smallerRight[i] - i;
            ans = (ans + (arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return (int)ans;
    }
};