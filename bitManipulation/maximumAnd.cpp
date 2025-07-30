// leet-2419

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd=nums[0];
        int curr=nums[0];
        int finall=1;
        int currLen=1;
        int i=1;
        while(i<nums.size()){
            if((curr&nums[i])==maxAnd){
                currLen++;
                finall=max(currLen,finall);
                curr=curr&nums[i];
            }
            if((curr&nums[i])>maxAnd){
                maxAnd=curr&nums[i];
                currLen++;
                finall=max(finall,currLen);
                curr=curr&nums[i];
            }
            if(nums[i]>maxAnd){
                curr=nums[i];
                finall=1;
                currLen=1;
                maxAnd=nums[i];
            }
            if((nums[i]<maxAnd) || (curr & nums[i])<maxAnd){
                curr=nums[i];
                finall=max(finall,currLen);
                currLen=1;
            }
            i++;
        }
        return finall;
    }
};