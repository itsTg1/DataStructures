class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        if(k==0 || k==1){
            return 0;
        }
        int minDiff=Integer.MAX_VALUE;
        int i=0;
        int j=0;
        while(j<nums.length){
            while(i<j && (j-i+1)>k){
                i++;
            }
            if((j-i+1)==k){
                minDiff=Math.min(minDiff,(nums[j]-nums[i]));

            }
            j++;
        }
        return minDiff;

    }
}