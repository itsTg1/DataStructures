class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prevIdx=0;
        int prevcnt=0;
        int ans=0;
        int cnt=1;
        int st=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                cnt++;
            }
            else{
                if(prevIdx==(st-1)){
                    
                    ans=max(ans,min(cnt,prevcnt));
                }
              
                // calculate in every case whether adjacent increasing subarrays are present or not .    
                ans=max(ans,cnt/2);
                
                prevcnt=cnt;
                prevIdx=i-1;
                st=i;
                cnt=1;
            }
        }
        if(prevIdx==(st-1)){
            ans=max(ans,min(cnt,prevcnt));
        }         
        ans=max(ans,cnt/2);
        return ans;


    }
};