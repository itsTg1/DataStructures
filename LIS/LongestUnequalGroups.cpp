class Solution {
public:
    vector<string> ans;
    void findSubsequence(vector<string>& words, vector<int>& groups,int curr,int prev,int len,vector<string> &temp){
        if(curr>=len){
            if(ans.size()<temp.size()){
                ans=temp;
            }
            return ;
        }
        if(prev==-1 || groups[curr]!=groups[prev]){
            temp.push_back(words[curr]);
            findSubsequence(words,groups,curr+1,curr,len,temp);
            temp.pop_back();
        }
        else{
            findSubsequence(words,groups,curr+1,prev,len,temp);
        }
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string> temp;
        findSubsequence(words,groups,0,-1,n,temp);
        return ans;
    }
};









// ---------------------------------------------------------------------------


class Solution {
public:
    
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string> result;
        vector<int> parent(n,-1);
        vector<int> dp(n,1);
        int LIS=1;
        int lisIdx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(groups[i]!=groups[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                    if(LIS<dp[i]){
                        LIS=dp[i];
                        lisIdx=i;
                    }
                }
            }
        }
        while(lisIdx!=-1){
            result.push_back(words[lisIdx]);
            lisIdx=parent[lisIdx];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};