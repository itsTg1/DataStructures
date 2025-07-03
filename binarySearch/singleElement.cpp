class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]==nums[mid+1]){
                if((e-mid)%2==0){
                    s=mid+2;
                }
                else{
                    
                    e=mid-1;
                }
            }
            if(nums[mid]!=nums[mid+1] ){
                if((e-mid)%2==0){
                    e=mid;
                }
                else{
                    s=mid+1;
                }
            }
        }
        return nums[e];
    }
};