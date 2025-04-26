// coder army


class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        int n=s.length();
        vector<int> len(n);
        len[0]=0;
        int temp=0;
        int i=1;
        while(i<n){
            if(s[temp]==s[i]){
                temp++;
                len[i]=temp;
                i++;
            }
            else{
                // yaha galti hogi
                if(temp==0){
                    len[i]=temp;
                    i++;
                }
                else{
                    temp=len[temp-1];
                }
            }
        }
        return len.back();
    }
};
