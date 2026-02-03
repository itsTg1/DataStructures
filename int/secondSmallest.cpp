class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int smallest=INT_MAX;
        int secsmallest=INT_MAX;
        int i=0;
        while(i<arr.size()){
            if(arr[i]<smallest){
                secsmallest=smallest;
                smallest=arr[i];
            }
            else if(arr[i]>smallest && arr[i]<secsmallest){
                secsmallest=arr[i];
            }
            i++;
        }
        if(secsmallest==INT_MAX){
            return {-1};
        }
        return {smallest,secsmallest};
        
    }
};