class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long maxSum=LLONG_MIN;
        vector<long long> prefixSum(nums.size());
        prefixSum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=0;i<k;i++){
            int j=i+k-1;
            long long currSum=0;
            int temi=i;
            while(j<nums.size()){
                long long subSum=prefixSum[j];
                if(temi>0){
                    subSum=prefixSum[j]-prefixSum[temi-1];
                }
                 
                currSum=max(subSum,currSum+subSum);
                maxSum=max(maxSum,currSum);
                temi=temi+k;
                j=temi+k-1;
            }
        }
        return maxSum;
    }
};