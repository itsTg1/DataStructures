// User function Template for C++

class Solution {
  public:
    void insertEle(stack<int> &st,int x){
        if(st.empty()){
            st.push(x);
            return ;
        }
        int ele=st.top();
        st.pop();
        insertEle(st,x);
        st.push(ele);
    }
    stack<int> insertAtBottom(stack<int> st, int x) {
        insertEle(st,x);
        return st;
    }
};