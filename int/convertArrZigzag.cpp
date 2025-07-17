
class Solution {
  public:
    void zigZag(vector<int> &arr) {
        // code here
        int i=0;
        bool ans=false;
        while(i<arr.size()){
            if((i+1)<arr.size()){
                if(!ans && arr[i+1]<arr[i]){
                    swap(arr[i+1],arr[i]);
                    ans=true;
                }
                else if(ans && arr[i+1]>arr[i]){
                    swap(arr[i+1],arr[i]);
                    ans=false;
                }
                else{
                    ans=!(ans);
                }
            }
            
            i++;
        }
       
    }
};