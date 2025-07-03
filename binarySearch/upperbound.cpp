class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here

        int lb=arr.size();
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>target){
                lb=min(lb,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return lb;
    }
};
