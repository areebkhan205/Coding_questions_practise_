class Solution {
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>>& o){
        int m=o.size();
        int n=o[0].size();
        if(i>=m || j>=n)return 0;
        if(o[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=solve(i+1,j,o);
        int down=solve(i,j+1,o);
        
    return  dp[i][j]=right+down;
    
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,o);
    }
};