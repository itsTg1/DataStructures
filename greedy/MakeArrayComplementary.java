// 1674------------------------

class Solution {
    public int minMoves(int[] nums, int limit) {
        int ans=Integer.MAX_VALUE;
        int n=nums.length;
        for(int i=2;i<=(2*limit);i++){
            int cnt=0;
            for(int j=0;j<(n/2);j++){
                int currSum=nums[j]+nums[n-j-1];
                int diff=Math.abs(i-currSum);
                if(diff==0){
                    cnt+=0;
                }
                else if(currSum>i){
                    int mini=Math.max(nums[j],nums[n-j-1])-diff;
                    if(mini>=1){
                        cnt+=1;
                    }
                    else{
                        cnt+=2;
                    }
                }
                else if(currSum<i){
                    int mini=Math.min(nums[j],nums[n-j-1])+diff;
                    if(mini<=limit){
                        cnt+=1;
                    }
                    else{
                        cnt+=2;
                    }
                }
                
            }
           
            ans=Math.min(ans,cnt);
        }
        return ans;
    }
}