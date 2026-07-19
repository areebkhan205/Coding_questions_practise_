class Solution {
    int dp[50][50][50][50];
    int solve(int r1,int c1,int r2,int c2,vector<vector<int>>& grid){
        int n=grid.size();
          if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
        if(dp[r1][c1][r2][c2]!=-1)return dp[r1][c1][r2][c2];
          int q1=grid[r1][c1];
          int q2=grid[r2][c2];
         int cheery=0;
           //same place
          if(r1==r2 && c1==c2){
           cheery+=grid[r1][c1];
           if(r1==n-1 && c1==n-1){
            return dp[r1][c1][r2][c2]=grid[r1][c1];
           }
           grid[r1][c1]=0;
          }
          else{
            cheery=grid[r1][c1]+grid[r2][c2];
            grid[r1][c1]=0;
            grid[r2][c2]=0;
          }


          int p1=solve(r1+1,c1,r2+1,c2,grid);
          int p2=solve(r1+1,c1,r2,c2+1,grid);
          int p3=solve(r1,c1+1,r2,c2+1,grid);
          int p4=solve(r1,c1+1,r2+1,c2,grid);
           grid[r1][c1]=q1;
           grid[r2][c2]=q2;
           return dp[r1][c1][r2][c2]=cheery+max({p1,p2,p3,p4});

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
          memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,grid);
      return max(0,ans);
    }
};