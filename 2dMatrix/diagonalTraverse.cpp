class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int rows=mat.size();
        int cols=mat[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        bool isRev=1;
        for(auto &it:mp){
            vector<int> temp=it.second;
            cout<<isRev<<" ";
            if(isRev==1){
                
                for(int i=temp.size()-1;i>=0;i--){
                    ans.push_back(temp[i]);
                }
                isRev=0;
            }
            else{
                for(int i=0;i<temp.size();i++){
                    ans.push_back(temp[i]);
                }
                isRev=1;
            }
            
        }
        return ans;
    }
};