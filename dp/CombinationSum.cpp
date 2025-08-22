// LEETCODE - 39



class Solution {
public:
    vector<vector<int>> result;
    void findCombinations(vector<int> &candidates,int target,vector<int> temp,int i){
        if(target==0){
            result.push_back(temp);
            return ;
        }
        if(i==0){
            if(target%candidates[0]==0){
                int times=target/candidates[0];
                for(int j=0;j<times;j++){
                    temp.push_back(candidates[0]);
                }
                result.push_back(temp);
            }
            return ;
        }
        findCombinations(candidates,target,temp,i-1);
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            findCombinations(candidates,target-candidates[i],temp,i);
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int n=candidates.size();
        findCombinations(candidates,target,temp,n-1);
        return result;
    }
};