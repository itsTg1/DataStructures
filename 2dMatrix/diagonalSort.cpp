// ---------------------------BRUTE FORCE----------------------------------------------------


vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {
                int temp = i;
                int coltem=j;
                vector<int> v;
                vector<pair<int, int>> tem;
                while (temp < row && coltem<col) {
                    if (!visited[temp][coltem]) {
                        v.push_back(mat[temp][coltem]);
                        tem.push_back({temp, coltem});
                        visited[temp][coltem] = 1;
                        temp++;
                        coltem++;
                    }
                    else{
                        break;
                    }
                }
                if(v.size()==0){
                    break;
                }
                sort(v.begin(), v.end());
                int idx = 0;
                for (int k = 0; k < tem.size(); k++) {
                    int first = tem[k].first;
                    int second = tem[k].second;
                    mat[first][second] = v[idx];
                    idx++;
                }
            }
        }
        return mat;
    }


// -----------------------------------------------------------------------------------------------------


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        map<int,vector<int>> mp;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &it:mp){

            sort(it.second.begin(),it.second.end());
        }
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                mat[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};