class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
            vis[i][j]=1;
            int ans=1;
            for(int k=0;k<4;k++){
                int nr=dr[k]+i;
                int nc=dc[k]+j;
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    ans+=solve(nr,nc,grid,vis);
                }
            }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
            
            int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(grid[i][j]==1  &&  !vis[i][j]){
                     ans=max(ans, solve(i,j,grid,vis));
                 }
            }
        }
    return ans;
    }
};