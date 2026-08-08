class Solution {
    int dp[201][201];
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};

    int dfs(int row,int col,vector<vector<int>>& matrix,int m,int n){
        
        if(dp[row][col]!=-1)return dp[row][col];
        int ans=1;

        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[row][col]){
                  ans=max(ans,1+dfs(nr,nc,matrix,m,n));
            }
        }
    
    return  dp[row][col]=ans;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         int m=matrix.size();
         int n=matrix[0].size();
       int maxans=INT_MIN;
       memset(dp,-1,sizeof(dp));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ans=dfs(i,j,matrix,m,n);
                maxans=max(ans,maxans);
            }
         }
    return maxans;
    }
};