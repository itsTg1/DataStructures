class Solution {
public:
    vector<vector<int>> ans;
    void findTriplet(int idx, int target, int s,vector<int>& nums) {
        int e = nums.size() - 1;

        while (s < e) {
            while (s < e && nums[s] + nums[e] > target) {
                e--;
            }
            while (s < e && nums[s] + nums[e] < target) {
                s++;
            }
            if (s < e && nums[s] + nums[e] == target) {
                vector<int> temp;
                temp.push_back(nums[idx]);
                temp.push_back(nums[s]);
                temp.push_back(nums[e]);
                ans.push_back(temp);
                int temp1 = nums[s];
                int temp2 = nums[e];
                while (s < e && nums[s] == temp1) {
                    s++;
                }
                while (s < e && nums[e] == temp2) {
                    e--;
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int ele = nums[i];
            int target = ele * (-1);
            findTriplet(i, target, i + 1,nums);
            while (i < nums.size() && nums[i] == ele) {
                i++;
            }
        }
        return ans;
    }
};