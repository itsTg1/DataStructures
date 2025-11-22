class Solution {
public:
    int numSub(string s) {
        long long mod=1e9+7;
        long long ans=0;
        int i=0;
        int j=0;
        int cntZ=0;
        int cnt1=0;
        while(j<s.length()){
            if(s[j]=='0'){
                cntZ++;
            }
            else{
                cnt1++;
            }
            while(i<j && cntZ>0){
                if(s[i]=='0'){
                    cntZ--;
                }
                else{
                    cnt1--;
                }
                i++;
            }
            if(cnt1>0){
                ans+=(long long)((long long)(j-i)+1)%mod;
            }
            j++;
        }
        return ans%mod;
    }
};