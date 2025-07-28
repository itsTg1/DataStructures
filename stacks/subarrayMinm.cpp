// galti kaha hogi - koi bhi ek mei = lagana chahe nextsmaller left mei ya next smaller right mei



class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st1;
        long long mod = 1e9 + 7;
        long long n = arr.size();
        // next smaller left;

        vector<int> nextLeft(n, -1);
        int i = arr.size() - 1;
        while (i >= 0) {
            while (!st1.empty() && arr[i] <= arr[st1.top()]) {
                nextLeft[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
            i--;
        }
        for (auto it : nextLeft) {
            cout << it << ",";
        }


        //    next smallest right
        stack<int> st;
        vector<int> nextRight(n, n);
        int j = 0;
        while (j < n) {
            while (!st.empty() && arr[j] < arr[st.top()]) {
                nextRight[st.top()] = j;
                st.pop();
            }
            st.push(j);
            j++;
        }


        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + (((long long)(i - nextLeft[i]) * (nextRight[i] - i)) %
                          mod * arr[i]) %
                             mod) %
                  mod;
        }

        return (int)sum;
    }
};