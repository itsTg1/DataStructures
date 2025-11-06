// similar like coins - infinite supply

class Solution {
public:
    vector<vector<int>> ans;
    void possibleCombinations(vector<int> &candidates,int i,int target,vector<int> &temp){
        if(i<0){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            possibleCombinations(candidates,i,target-candidates[i],temp);
            temp.pop_back();
        }
        possibleCombinations(candidates,i-1,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size=candidates.size();
        int i=size-1;
        vector<int> temp;
        possibleCombinations(candidates,i,target,temp);
        return ans;
    }
};