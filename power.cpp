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