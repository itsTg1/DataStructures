class Solution {
public:
    bool binarySearch(int i,int j,vector<vector<int>> &matrix,int target){
    
        int col1=0;
       
        int col2=j;
        while(col1<=col2){
            int mid=col1+(col2-col1)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]>target){
                col2=mid-1;
            }
            else{
                col1=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        bool ans=false;
        while(i<matrix.size()){
            if(matrix[i][j]<target){
                i++;
            }
            else if(matrix[i][j]>target){
                if(binarySearch(i,j,matrix,target)){
                    return true;
                }
                i++;
            }
            else{
                return true;
            }
            
        }
        return ans;
    }
};