class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};

    void solve(int  i,int j ,vector<vector<char>> &grid){
            int m=grid.size();
           int n=grid[0].size();
           grid[i][j]='0';
           for(int k=0;k<4;k++){
             int nr=dr[k]+i;
             int nc=dc[k]+j;

              if(nr<m && nc<n && nr>=0 && nc>=0 && grid[nr][nc]=='1'){
                            grid[nr][nc]='0';
                            solve(nr,nc,grid);
              }
           }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
           int m=grid.size();
           int n=grid[0].size();
                  
                  int cnt=0;
              for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                        if(grid[i][j]=='1'){
                            solve(i,j,grid);
                            cnt++;
                        }
                }
              }
    return cnt;
    }
};