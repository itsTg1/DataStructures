class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n=nums.size();
            long long result=0;
            long long currPairs=0;
            int i=0;
            int j=0;
            unordered_map<int,int> mp;
            while(j<nums.size()){
                currPairs+=mp[nums[j]];
                mp[nums[j]]++;
                while(i<=j && currPairs>=k){
                    result+=(n-j);
                    mp[nums[i]]--;
                    currPairs-=mp[nums[i]];
                    i++;
                }
                j++;
            }
            return result;
        }
    };