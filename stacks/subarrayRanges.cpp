class Solution {
public:
    vector<int> nextSmallerRight(vector<int> &nums){
        vector<int> ans(nums.size(),nums.size());
        int i=0;
        stack<int> st;
        while(i<nums.size()){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        return ans;
    }
    vector<int> nextSmallerLeft(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && nums[st.top()]>nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        return ans;

    }
    vector<int> nextGreaterLeft(vector<int> &nums){
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        return ans;
    }
    vector<int> nextGreaterRight(vector<int> &nums){
        vector<int> ans(nums.size(),nums.size());
        int i=0;
        stack<int> st;
        while(i<nums.size()){
            while(!st.empty() && nums[st.top()]<nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        return ans;
    }
    long long maxSum(vector<int>& arr) {
        vector<int> greatLeft = nextGreaterLeft(arr);
        vector<int> greatRight = nextGreaterRight(arr);
        long long sum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long tem =
                ((long long)(greatRight[i] - i) * (i - greatLeft[i]))* arr[i];
            sum = (sum + tem);
        }
        return sum;
    }
    long long minSum(vector<int>& arr) {
        vector<int> greatLeft = nextSmallerLeft(arr);
        vector<int> greatRight = nextSmallerRight(arr);
        long long sum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long tem =
                ((long long)(greatRight[i] - i) * (i - greatLeft[i]))* arr[i];
            sum = (sum + tem);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long maxSubarray=maxSum(nums);
        long long minSubarray=minSum(nums);
        return maxSubarray-minSubarray;
    }
};