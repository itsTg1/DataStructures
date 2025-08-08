class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        if(arr.size()==1){
            return ;
        }
        int i=1;
        while(i<arr.size()){
            if(i>0 && arr[i]<arr[i-1]){
                swap(arr[i],arr[i-1]);
                i--;
            }
            else{
                i++;
            }
        }
    }
};