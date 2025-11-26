class Solution {
  public:
    vector<int> findSmallestRight(vector<int> heights){
        stack<int> st;
        vector<int> nextSmallest(heights.size(),heights.size());
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                nextSmallest[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return nextSmallest;
        
    }
    vector<int> findSmallestLeft(vector<int> heights){
        stack<int> st;
        vector<int> nextSmallest(heights.size(),-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                nextSmallest[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return nextSmallest;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int ans=0;
        vector<int> heights(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    heights[j]=0;
                }
                else{
                    heights[j]=heights[j]+1;
                }
            }
            
    
            vector<int> smallestRight=findSmallestRight(heights);
            vector<int> smallestLeft=findSmallestLeft(heights);
            for(int i=0;i<heights.size();i++){
                ans=max(ans,(heights[i]*(smallestRight[i]-smallestLeft[i]-1)));
            }
        }
        return ans;
    }
};