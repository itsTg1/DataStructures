
class Solution {
  public:
    vector<string> result;
    void findWord(int i,int j,vector<vector<char>>& mat, string& word,int idx,string &temp){
        if(idx>=word.length()){
            if(temp==word){
                result.push_back(temp);
            }
            return;
        }
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]=='$'){
            return ;
        }
        if(mat[i][j]!=word[idx]){
            return ;
        }
        char tem=mat[i][j];
        if(mat[i][j]==word[idx]){
            temp+=mat[i][j];
            mat[i][j]='$';
            
        }
        findWord(i+1,j,mat,word,idx+1,temp);
        findWord(i-1,j,mat,word,idx+1,temp);
        findWord(i,j-1,mat,word,idx+1,temp);
        findWord(i,j+1,mat,word,idx+1,temp);
        
        mat[i][j]=tem;
        temp=temp.substr(0,temp.length()-1);
        
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        bool ans=false;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==word[0]){
                    string temp="";
                    
                    findWord(i,j,mat,word,0,temp);
                    
                      
                }
            }
        }
        if(result.size()>0){
            return true;
        }
        return ans;
    }
};