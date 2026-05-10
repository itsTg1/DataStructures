class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans=LLONG_MAX;
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        long long orignalSum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();){
            int ele=nums[i];
            long long sum=0;
            // instead of traversing all the remaining elements we are only 
            // going through the multiple of ele if it is present in the arr
            // then we are transforming it else not..
            for(int j=ele;j<=nums[nums.size()-1];j=j+ele){
                if(mp.find(j)==mp.end()){
                    continue;
                }
                if(st.count(j)==0 && j%nums[i]==0){
                    sum+=(1LL*mp[j]*nums[i]);
                    st.insert(j);
                }
            
                
            }
            
            orignalSum+=sum;
            st.insert(nums[i]);
            i+=mp[nums[i]];
        }
        return orignalSum;
    }
};