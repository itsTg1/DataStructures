class Solution {
    public:
        void generateSubset(vector<int>& nums,int &ans,int temp,int i){
            if(i>=nums.size()){
                ans+=temp;
                return ;
            }
            generateSubset(nums,ans,temp^nums[i],i+1);
            generateSubset(nums,ans,temp,i+1);
        }
        int subsetXORSum(vector<int>& nums) {
            int ans=0;
            generateSubset(nums,ans,0,0);
            return ans;
    
        }
    };