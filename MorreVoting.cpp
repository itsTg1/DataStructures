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



    // ----------------------------------------------------------------------
    // n/3 majority element ..

    class Solution {
        public:
            vector<int> majorityElement(vector<int>& nums) {
                int cnt1=0;
                int cnt2=0;
                int ele1=NULL;
                int ele2=NULL;
                for(int i=0;i<nums.size();i++){
                    if(ele1==nums[i]){
                        cnt1++;
                    }
                    else if(ele2==nums[i]){
                        cnt2++;
                    }
                    else if(cnt1==0){
                        ele1=nums[i];
                        cnt1=1;
                    }
                    else if(cnt2==0){
                        ele2=nums[i];
                        cnt2=1;
                    }
                    else{
                        cnt1--;
                        cnt2--;
                    }
                }
                int freq1=0;
                int freq2=0;
                for(auto it:nums){
                    if(it==ele1){
                        freq1++;
                    }
                    else if(it==ele2){
                        freq2++;
                    }
                }
                vector<int> ans;
                if(freq1 > floor(nums.size()/3)){
                    ans.push_back(ele1);
                }
                if(freq2 > floor(nums.size()/3)){
                    ans.push_back(ele2);
                }
                return ans;
            }
        };