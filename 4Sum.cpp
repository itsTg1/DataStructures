class Solution {
    public:
        vector<vector<int>> ans;
        void twoSum(vector<int>& nums, long long target, int s, int t) {
            int i = s + 1;
            int j = nums.size() - 1;
            while (i < j) {
                vector<int> temp;
                while (i < j && nums[i] + nums[j] < target) {
                    i++;
                }
                while (i < j && nums[i] + nums[j] > target) {
                    j--;
                }
                if (i<j && nums[i] + nums[j] == target) {
                    int it = nums[i];
                    int jt = nums[j];
                    temp.push_back(nums[t]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    ans.push_back(temp);
                    while (i < j && nums[i] == it) {
                        i++;
                    }
                    while (i < j && nums[j] == jt) {
                        j--;
                    }
                }
            }
        }
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n - 4; ) {
            for (int j = i + 1; j <= n - 3; ) {
                long long  tofind = (long long)(target - (long long)(nums[i] + nums[j]));
                twoSum(nums, tofind, j, i); // use j, i instead of s, t
                int tempJ = nums[j];
                while (j <= n - 3 && nums[j] == tempJ) {
                    j++;
                }
            }
            int tempI = nums[i];
            while (i <= n - 4 && nums[i] == tempI) {
                i++;
            }
        }
        return ans;
    }
    
    };