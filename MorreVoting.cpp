//ele--> it will store in end element with >n/2 occurences
// cnt-> concept is that cnt of majority element cannot be cancelled bcz more than
// half of array is consisted of it only..

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int ele=0;
            int cnt=0;
            int n=nums.size();
            for(int i=0;i<nums.size();i++){
                if(cnt==0){
                    ele=nums[i];
                    cnt=1;
                }
                else if(nums[i]==ele){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            int cnt1=0;
            for(auto it:nums){
                if(it==ele){
                    cnt1++;
                }
            }
            if(cnt1>n/2){
                return ele;
            }
            return -1;
        }
    };