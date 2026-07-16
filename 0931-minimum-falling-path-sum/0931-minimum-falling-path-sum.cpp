class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        for (int i = 0; i < matrix.size(); i++) {
            ans = min(ans, helper(matrix, 0, i, dp));
        }
        return ans;
    }

public:
    int helper(vector<vector<int>>& matrix, int i, int j,
               vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (j < 0 || j >= n)
            return 1e9;
        if (i < 0 || i >= m)
            return 1e9;
        if (i == m - 1)
            return matrix[i][j];
        if (dp[i][j] != 1e9)
            return dp[i][j];
        int one = matrix[i][j] + min(helper(matrix, i + 1, j - 1, dp),
                                     min(helper(matrix, i + 1, j, dp),
                                         helper(matrix, i + 1, j + 1, dp)));
        return dp[i][j] = one;
    }
};