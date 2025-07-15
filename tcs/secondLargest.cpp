class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int prev=-1;
        int largest=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>largest){
                prev=largest;
                largest=arr[i];
            }
            else if(arr[i]>prev && arr[i]<largest){
                prev=arr[i];
            }
        }
        return prev;
    }
};