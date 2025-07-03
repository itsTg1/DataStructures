class Solution {
public:
    int findmin(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
    int binarysearch(vector<int>& nums,int s,int e,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=findmin(nums);
        if(index==0){
            int ans=binarysearch(nums,0,nums.size()-1,target);
            return ans;
        }
        else{
            int ans=binarysearch(nums,0,index-1,target);
            if(ans!=-1){
                return ans;
            }
        }
        return binarysearch(nums,index,nums.size()-1,target);
    }
};