class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        while(st.size()>1){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(mat[first][second]==1 && mat[second][first]!=1){
                st.push(second);
            }
            else if(mat[first][second]!=1 && mat[second][first]==1){
                st.push(first);
            }
        }
        if(st.empty()){
            return -1;
        }
        int n=mat.size();
        int ans=st.top();
        st.pop();
        
        int row=0;
        int col=0;
        for(int i=0;i<mat.size();i++){
            row+=mat[ans][i];
            col+=mat[i][ans];
        }
        if(row==1 && col==n){
            return ans;
        }
        return -1;
    }
};