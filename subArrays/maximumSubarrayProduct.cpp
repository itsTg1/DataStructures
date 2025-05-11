class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int prefix=1;
            int suffix=1;
            int maxSum=INT_MIN;
            int n=nums.size();
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0 && nums[n-i-1]!=0){
                    prefix=1;
                    suffix=suffix*nums[n-i-1];
                    maxSum=max(maxSum,max(0,suffix));
                }
                if(nums[n-i-1]==0 && nums[i]!=0){
                    suffix=1;
                    prefix=prefix*nums[i];
                    maxSum=max(maxSum,max(prefix,0));
                }
                if(nums[n-i-1]!=0 && nums[i]!=0){
                    prefix=prefix*nums[i];
                    suffix=suffix*nums[n-i-1];
                    maxSum=max(maxSum,max(prefix,suffix));
                }
                if(nums[n-i-1]==0 && nums[i]==0)
                {
                    prefix=1;
                    suffix=1;
                    maxSum=max(maxSum,0);
                }
            }
            return maxSum;
        }
    };