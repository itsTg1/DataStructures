// https://www.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1?page=2



class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int tem=1000001;
        int minNo=1;
        int maxNo=1;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                // we want here max no
                int mod=arr[n-maxNo]%tem;
                arr[i]=(mod*tem)+arr[i];
                maxNo++;
            }
            else{
                int mod=arr[minNo-1]%tem;
                arr[i]=(mod*tem)+arr[i];
                minNo++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=arr[i]/tem;
        }
    }
};