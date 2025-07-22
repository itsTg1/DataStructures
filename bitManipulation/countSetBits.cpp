class Solution {
public:
    static bool mycomp(int &a,int &b){
        int n1=__builtin_popcount(a);
        int n2=__builtin_popcount(b);
        if(n1==n2){
            return a<b;
        }
        return n1<n2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),mycomp);
        return arr;
    }
};