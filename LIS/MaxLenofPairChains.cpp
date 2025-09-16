class Solution {
public:
    vector<vector<int>> pairs;
    vector<vector<int>> dp;

    int findMaxChain(int i, int prevIndex) {
        if (i >= pairs.size()) {
            return 0;
        }
        if (dp[i][prevIndex + 1] != -1) {
            return dp[i][prevIndex + 1];
        }

        // Option 1: skip the current pair
        int notTake = findMaxChain(i + 1, prevIndex);

        // Option 2: take the current pair if it can be chained
        int take = 0;
        if (prevIndex == -1 || pairs[prevIndex][1] < pairs[i][0]) {
            take = 1 + findMaxChain(i + 1, i);
        }

        return dp[i][prevIndex + 1] = max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairsInput) {
        pairs = pairsInput;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Sort by end value for optimal chaining
        });

        int n = pairs.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return findMaxChain(0, -1);
    }
};
