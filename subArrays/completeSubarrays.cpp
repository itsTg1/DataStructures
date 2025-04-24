class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            set<int> st;
            for(auto it:nums){
                st.insert(it);
            }
            int distinct=st.size();
            set<int> st1;
            int ans=0;
            vector<int> store(2002,0);
            int i=0;
            int j=0;
            while(j<nums.size()){
                st1.insert(nums[j]);
                store[nums[j]+1]++;
                while(i<=j && st1.size()==distinct){
                    ans+=(nums.size()-j);
                    store[nums[i]+1]--;
                    if(store[nums[i]+1]==0){
                        st1.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
            return ans;
        }
    };