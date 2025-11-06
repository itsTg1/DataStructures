class Solution {
public:
    int smallestNumber(int n) {
        
        int i=n+1;
        while((n&i)!=0){
            i++;
        }
        
        return i-1;
    }
};