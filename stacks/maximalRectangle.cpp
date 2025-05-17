class Solution {
  public:
  vector<int> smallerLeft(vector<int> &temp){
        stack<int> st;
        vector<int> v(temp.size(),-1);
        int i=temp.size()-1;
        while(i>=0){
            while(!st.empty() && temp[st.top()]>temp[i]){
                v[st.top()]=i;
                st.pop();
            }
            st.push(i);i--;
        }
        return v;
    }
    vector<int> smallerRight(vector<int> &temp){
        stack<int> st;
        vector<int> v(temp.size(),temp.size());
        int i=0;
        while(i<temp.size()){
            while(!st.empty() && temp[st.top()]>=temp[i]){
                v[st.top()]=i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        return v;
    }
    int findArea(vector<int> &temp){
        vector<int> smallRight=smallerRight(temp);
        vector<int> smallLeft=smallerLeft(temp);
        int ans=0;
        for(int i=0;i<temp.size();i++){
            int tem=temp[i]*((i-smallLeft[i]) + (smallRight[i]-i)-1);
            ans=max(tem,ans);
        }
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        for(int j=0;j<mat[0].size();j++){
            int sum=0;
            for(int i=0;i<mat.size();i++){
                sum+=mat[i][j];
                if(mat[i][j]==0){
                    sum=0;
                }
                else{
                    mat[i][j]=sum;
                }
            }
        }
        int ans=0;
        for(auto it:mat){
            vector<int> temp;
            for(auto i:it){
                temp.push_back(i);
            }
            int tem=findArea(temp);
            ans=max(tem,ans);
        }
        return ans;
    }
};