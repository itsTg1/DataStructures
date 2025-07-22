long long M=1e9 + 7;
int findPower(long long a,long long b){
    if(b==0){
        return 1;
    }
    long long half=findPower(a,b/2);
    long long result= (half*half)%M;
    if(b%2==1){
        result=(result*a)%M;
    }
    return result;
}



// -------------------------------------------------------------------------------------------

class Solution {
public:
    typedef long long ll;
    double findpow(double x,ll n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return findpow(1/x,(ll)(-(ll)(n)));
        }
        double halfresult=(double)findpow(x,n/2);
        double result=(double)(halfresult*halfresult);
        if(n&1==1){
            result=(double)result*x;
        }
        return result;
    }
    double myPow(double x, int n) {
        return findpow(x,(ll)(n));
    }
};

