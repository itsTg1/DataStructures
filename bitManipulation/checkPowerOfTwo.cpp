class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        long long prev=(long long)n-1;
        return (prev & n)==0;
    }
};