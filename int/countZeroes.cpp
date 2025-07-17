class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int cntZero=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                cntZero++;
            }
        }
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                arr[j]=arr[i];
                j++;
            }
        }
        while(j<arr.size()){
            arr[j]=0;
            j++;
        }
    }
};