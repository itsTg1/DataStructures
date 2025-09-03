
class Solution {
  public:
    void insertAtBottom(stack<int> &st,int ele){
        if(st.empty()){
            st.push(ele);
            return ;
        }
        int tem=st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(tem);
    }
    void reverseStack(stack<int> &st){
        if(st.empty()){
            return ;
        }
        int ele=st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st,ele);
        
    }
    void reverse(stack<int> &st) {
        // code here
        reverseStack(st);
        
    }
};