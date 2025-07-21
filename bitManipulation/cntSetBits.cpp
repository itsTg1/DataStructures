class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt=0;
        while(n>1){
            // to check whether remainder is 0
            // for any odd number last bit is always 1
            if((n&1)==1){
                cnt++;
            }
            // n=n/2
            n=n>>1;
        }
        if(n==1){
            cnt++;
        }
        return cnt;
    }
};