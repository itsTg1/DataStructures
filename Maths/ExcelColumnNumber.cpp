class Solution {
public:
    int titleToNumber(string columnTitle) {

        int siz=columnTitle.length();
        long long unsigned int ans=0;
        long long unsigned int x=1;
        for(int i=siz-1;i>=0;i--){
            long long unsigned int temp=(columnTitle[i]-'A'+1)*x;
            x=x*26;
            ans+=temp;
        }
        return ans;
    }
};