class Solution {
    int dr[8]={0,1,0,-1,1,1,-1,-1};
    int dc[8]={-1,0,1,0,-1,1,1,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
             queue<pair<int,pair<int,int>>> qu;
             qu.push({1,{0,0}});

         while(!qu.empty()){
               int step=qu.front().first;
               int row=qu.front().second.first;
               int col=qu.front().second.second;
                        grid[row][col]=1;
               if(row==n-1 && col==m-1)return step;

                qu.pop();

                for(int i=0;i<8;i++){
                       int nr=dr[i]+row;
                       int nc=dc[i]+col;
                       if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0 ){
                            grid[nr][nc]=1;
                             qu.push({step+1,{nr,nc}});
                       }
                }
         }
    return -1;
    }
};