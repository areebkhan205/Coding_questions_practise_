class Solution {
int dp[201][201];
bool vis[201][201];

int solve(int row, int prevcol, vector<vector<int>>& grid) {
    int n = grid.size();

    if (row == n) return 0;

    if (vis[row][prevcol + 1])
        return dp[row][prevcol + 1];

    vis[row][prevcol + 1] = true;

    int ans = INT_MAX;

    for (int col = 0; col < n; col++) {
        if (col == prevcol) continue;

        ans = min(ans, grid[row][col] + solve(row + 1, col, grid));
    }

    return dp[row][prevcol + 1] = ans;
}
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(vis,0,sizeof(vis));
            memset(dp,-1,sizeof(dp));
        return solve(0,-1,grid);
    }
};