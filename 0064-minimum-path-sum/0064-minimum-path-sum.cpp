class Solution {
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1)return grid[i][j];
        if(i>=m || j>=n)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int down=grid[i][j]+solve(i+1,j,grid);
        int up=grid[i][j]+solve(i,j+1,grid);
        return dp[i][j]=min(up,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};