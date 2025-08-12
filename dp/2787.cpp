class Solution {
public:
    long long mod = 1e9 + 7;

    // Integer power function (no floating point)
    long long powerLL(long long base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    int findWays(vector<long long>& powers, int idx, long long sum, int n, vector<vector<int>>& dp) {
        if (sum == n) return 1;
        if (sum > n || idx >= powers.size()) return 0;

        if (dp[idx][sum] != -1) return dp[idx][sum];

        long long include = findWays(powers, idx + 1, sum + powers[idx], n, dp) % mod;
        long long exclude = findWays(powers, idx + 1, sum, n, dp) % mod;

        return dp[idx][sum] = (include + exclude) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<long long> powers;

        // Precompute all powers <= n
        for (int i = 1; ; i++) {
            long long p = powerLL(i, x);
            if (p > n) break;
            powers.push_back(p);
        }

        // DP table: dp[idx][sum]
        vector<vector<int>> dp(powers.size(), vector<int>(n + 1, -1));

        return findWays(powers, 0, 0, n, dp);
    }
};
