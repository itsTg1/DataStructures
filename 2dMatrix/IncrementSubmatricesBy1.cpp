class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n,vector<int>(n,0));
        for(auto it:queries){
            int row1=it[0];
            int col1=it[1];
            int row2=it[2];
            int col2=it[3];
            for(int i=row1;i<=row2;i++){
                result[i][col1]++;
                if((col2+1)<n){
                    result[i][col2+1]--;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                result[i][j]=result[i][j]+result[i][j-1];
            }
      
        }
        return result;
    }
};