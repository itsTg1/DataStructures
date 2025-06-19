class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        
        for(auto it:v){
            int i=it.first;
            int j=it.second;
            for(int k=0;k<matrix[0].size();k++){
                matrix[i][k]=0;
            }
            for(int k=0;k<matrix.size();k++){
                matrix[k][j]=0;
            }
        }
        
    }
};