class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> prefixes;

        // Store all prefixes of arr1 numbers
        for(int x : arr1){
            while(x > 0){
                prefixes.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of arr2 numbers
        for(int x : arr2){

            int num = x;

            while(num > 0){

                if(prefixes.count(num)){
                    ans = max(ans, (int)to_string(num).length());
                    break;
                }

                num /= 10;
            }
        }

        return ans;
    }
};