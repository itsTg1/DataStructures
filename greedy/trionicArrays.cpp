class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool ans=false;
        int i=1;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        int prev=nums[0];
        while(i<nums.size() && nums[i]>prev){
            cnt1++;
            prev=nums[i];
            i++;
        }
        while(i<nums.size() && nums[i]<prev){
            cnt2++;
            prev=nums[i];
            i++;
        }
        while(i<nums.size() && nums[i]>prev){
            cnt3++;
            prev=nums[i];
            i++;
        }
        if(i<nums.size()){
            return false;
        }
        if(cnt1>=1 && cnt2>=1 && cnt3>=1){
            ans=true;
        }
        return ans;
    }
};