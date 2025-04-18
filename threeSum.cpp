class Solution {
    public:
    
        void findsum(vector<int>& nums, int idx,
                     vector<vector<int>>& ans,int target) {
    
            int s=idx;
            int e=nums.size()-1;
            while(s<e){
                vector<int> temp;
                while(s<e && nums[s]+nums[e]<target){
                    s++;
                }
                while(s<e && nums[s]+nums[e]>target){
                    e--;
                }
                if(s<e && nums[s]+nums[e]==target){
                    temp.push_back(nums[idx-1]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    ans.push_back(temp);
                    int it=nums[s];
                    int jt=nums[e];
                    while(s<e && nums[s]==it){
                        s++;
                    }
                    while(s<e && nums[e]==jt){
                        e--;
                    }
    
                }
            }
            
        }
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            for(int i=0;i<=nums.size()-3;){
                int tar=(-1)*(nums[i]);
                findsum(nums,i+1,ans,tar);
                int temp=nums[i];
                while(i<=nums.size()-3 && nums[i]==temp){
                    i++;
                }
            }
            return ans;
        }
    };