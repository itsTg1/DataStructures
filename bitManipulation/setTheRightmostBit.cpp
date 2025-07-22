https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1


class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int ans=n | (n+1);
        return ans;
    }
};