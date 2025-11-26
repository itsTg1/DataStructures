class Solution {
public:
    // galti yaha hogi
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


// ----------------------------------------------------------------------------


class Solution {
  public:
    int findMin(vector<int> &arr){
        int s=0;
        int ans=-1;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<=arr[arr.size()-1]){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int binarySearch(vector<int> &arr,int s,int e,int target){
        int ans=-1;
        int st=s;
        int en=e;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }
        return ans;
    }
    int search(vector<int>& arr, int key) {
        // Code Here
        int minIdx=findMin(arr);
        if(arr[minIdx]==key){
            return minIdx;
        }
        int ans1=binarySearch(arr,0,minIdx-1,key);
        if(ans1!=-1){
            return ans1;
        }
        return binarySearch(arr,minIdx,arr.size()-1,key);
        
    }
};