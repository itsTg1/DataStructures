class Solution {
    public int findPeakElement(int[] nums) {
       
        for(int i=0;i<nums.length;i++){
            int left=Integer.MIN_VALUE;
            int right=Integer.MIN_VALUE;
            if((i-1)>=0){
                left=nums[i-1];
            }
            if((i+1)<nums.length){
                right=nums[i+1];
            }
            if(nums[i]>left && nums[i]>right){
                return i;
            }
        }
        return 0;
    }
}