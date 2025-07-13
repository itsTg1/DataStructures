class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int currSum=0;
        for(int i=0;i<arr.size();i++){
            
            if((currSum)==(sum-arr[i]-currSum)){
                return "true";
            }
            currSum+=arr[i];
        }
        return "false";
    }
};