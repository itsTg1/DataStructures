class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int circleIdx=-1;
        int swapIdx=-1;
        
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                circleIdx=i-1;
                break;
            }
        }
        if(circleIdx!=-1){
            for(int i=arr.size()-1;i>=circleIdx+1;i--){
                if(arr[i]>arr[circleIdx]){
                    swapIdx=i;
                    swap(arr[i],arr[circleIdx]);
                    break;
                }
            }
        }
        
        reverse(arr.begin()+circleIdx+1,arr.end());
        
    }
};