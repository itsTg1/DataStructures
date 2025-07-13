// leetcode 55

class Solution {
public:
    bool canJump(vector<int>& nums) {
       for(int i=0;i<nums.size();){
        if((i+nums[i])>=nums.size()-1){
            return true;
        }
        if(nums[i]==0 && i!=nums.size()-1){
            return false;
        }
        int curr=0;
        int idx=i;
        for(int j=0;j<=nums[i];j++){
            if((i+j)<nums.size()){
                if((nums[i+j]+j)>=curr){
                    curr=nums[i+j]+j;
                    idx=i+j;
                }
            }
        }
        i=idx;
       }
       return false; 
    }
};