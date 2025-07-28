class Solution {
public:
    vector<int> smallerLeft(vector<int>& arr) {
        stack<int> st;
        vector<int> v(arr.size(), -1);
        int i = arr.size() - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        return v;
    }
    vector<int> smallerRight(vector<int>& arr) {
        stack<int> st;
        vector<int> v(arr.size(), arr.size());
        int i = 0;
        while (i < arr.size()) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        return v;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> smallLeft = smallerLeft(arr);
        vector<int> smallRight = smallerRight(arr);
        long long sum = 0;
       
        for (int i = 0; i < arr.size(); i++) {
            long long tem =
                ((long long)(smallRight[i] - i) * (i - smallLeft[i]))*arr[i];
            sum = (sum + tem);
        }
        return sum;
    }
    vector<int> greaterLeft(vector<int>& arr) {
        stack<int> st;
        vector<int> v(arr.size(), -1);
        int i = arr.size() - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        return v;
    }
    vector<int> greaterRight(vector<int>& arr) {
        stack<int> st;
        vector<int> v(arr.size(), arr.size());
        int i = 0;
        while (i < arr.size()) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        return v;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> greatLeft = greaterLeft(arr);
        vector<int> greatRight = greaterRight(arr);
        long long sum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            long long tem =
                ((long long)(greatRight[i] - i) * (i - greatLeft[i]))* arr[i];
            sum = (sum + tem);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sumMin=sumSubarrayMins(nums);
        long long sumMax=sumSubarrayMaxs(nums);
        return sumMax-sumMin;
    }
};