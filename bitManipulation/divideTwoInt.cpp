class Solution {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        long long ans=0;
        bool sign=true;
        if(dividend<0 && divisor>0){
            sign=false;
        }
        if(dividend>0 && divisor<0){
            sign=false;
        }
        long long n=abs((long long)(dividend));
        long long d=abs((long long)(divisor));
        while(n>=d){
            int cnt=0;
            while(n>=(long long)(d*((long long)1<<(cnt+1)))){
                cnt++;
            }
            ans=(long long)(ans+(1ll<<cnt));
            n=n-(long long)(d*(1ll<<(cnt)));
        }
        if(ans>=INT_MAX && sign==true){
            return INT_MAX;
        }
        if(ans<=INT_MIN && sign==false){
            return INT_MIN;
        }
        return sign?ans:(-1)*ans;
    }
};