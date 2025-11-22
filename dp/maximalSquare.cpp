// User function Template for C++

class Solution {
  public:
    int findMax(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp, int m, int n){
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // IMPORTANT: if current cell is 0, it cannot be part of a 1-square
        if(mat[i][j] == 0) {
            dp[i][j] = 0;
            return 0;
        }

        int right = findMax(mat, i, j+1, dp, m, n);
        int down  = findMax(mat, i+1, j, dp, m, n);
        int diag  = findMax(mat, i+1, j+1, dp, m, n);
        return dp[i][j] = 1 + min({right, down, diag});
    }

    int maxSquare(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 1){
                    ans = max(ans, findMax(mat, i, j, dp, m, n));
                }
            }
        }
        return ans;
    }
};
