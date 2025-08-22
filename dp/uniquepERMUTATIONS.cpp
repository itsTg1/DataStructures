// User function Template for C++

class Solution {
  public:
    set<vector<int>> ans;
    void findPerms(vector<int> &nums,int idx){
        if(idx>=nums.size()){
            ans.insert(nums);
            return ;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            findPerms(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& nums) {
        // code here
        vector<vector<int>> result;
        
        findPerms(nums,0);

        for(auto it:ans){
            result.push_back(it);
        }
        return result;
    }
};