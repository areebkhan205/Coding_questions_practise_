class Solution {
int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};
int dp[51][51][51];
 static const int MOD=1e9+7;
    int solve(int i,int j,int maxm,int m,int n){
           if(i>=m || j>=n || i<0 || j<0)return 1;
          if(maxm==0)return 0;
          if(dp[i][j][maxm]!=-1)return dp[i][j][maxm];
             long long ans=0;
          for(int a=0;a<4;a++){
            int nr=dr[a]+i;
            int nc=dc[a]+j;
               ans= (ans+solve(nr,nc,maxm-1,m,n))%MOD;
          }
    return dp[i][j][maxm]= ans;
    }
public:
    int findPaths(int m, int n, int maxm, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return solve(sr,sc,maxm,m,n);
    }
};