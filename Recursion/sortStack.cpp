#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &st,int ele){
    if(st.empty() || (st.top()<ele)){
        st.push(ele);
        return ;
    }
    int tem=st.top();
    st.pop();
    sortedInsert(st,ele);
    st.push(tem);
}
void sortStack(stack<int> &st){
    if(st.empty()){
        return ;
    }
    int ele=st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st,ele);
    
}
int main() {
    stack<int> st;
    st.push(5);
    st.push(8);
    st.push(2);
    st.push(3);
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}


// --------------------------****-----------------------------------------------------------------------

class Solution {
  public:
    void insertSorted(stack<int> &st,int ele){
        if(st.empty() || st.top()<=ele){
            st.push(ele);
            return ;
        }
        int topEle=st.top();
        st.pop();
        insertSorted(st,ele);
        st.push(topEle);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return ;
        }
        int ele=st.top();
        st.pop();
        sortStack(st);
        insertSorted(st,ele);
    }
};
