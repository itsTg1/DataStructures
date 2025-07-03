class Solution {
public:
int findmin(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        int ans=0;
        while(s<e){
            while(s<e && nums[s]==nums[s+1]){
                s++;
            }
            while(s<e && nums[e]==nums[e-1]){
                e--;
            }
            int mid=s+(e-s)/2;
            cout<<mid<<endl;
            if(nums[mid]<=nums[e]){
                
                e=mid;;
            }
            else{
                s=mid+1;
            }
        }
        return e;
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
    bool search(vector<int>& nums, int target) {
        int index=findmin(nums);
        if(nums[index]==target){
            return true;
        }
        cout<<index;
        if(index==0){
            int ans=binarysearch(nums,0,nums.size()-1,target);
            if (ans!=-1){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            int ans=binarysearch(nums,0,index-1,target);
            if(ans!=-1){
                return true;
            }
        }
        int ans=binarysearch(nums,index,nums.size()-1,target);
        if(ans!=-1){
            return true;
        }
        return false;
    }
};