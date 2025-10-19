class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int remainder=((nums[i]%value)+value)%value;
            mp[remainder]++;
        }
        
        // ---- Find smallest missing integer ----
        int i = 0;
        while(mp[i%value]>0){
            mp[i%value]--;
            i++;
        }

        return i;
    }
};
