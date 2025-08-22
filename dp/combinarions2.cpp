class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int target, vector<int>& temp, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; // No need to continue (sorted)

            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], temp, i + 1); // move forward
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort first
        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return ans;
    }
};
