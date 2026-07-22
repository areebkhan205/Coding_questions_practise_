class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,pair<int,int>>> qu;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                 qu.push({0,{i,j}});
                }
            }
        }
        int maxtime=0;
        while(!qu.empty()){
            int time=qu.front().first;
            int row=qu.front().second.first;
            int col=qu.front().second.second;
            qu.pop();
                 maxtime=max(time,maxtime);
            for(int i=0;i<4;i++){
                int nr=dr[i]+row;
                int nc=dc[i]+col;
                if(nr<m && nc<n && nr>=0 && nc>=0 && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    qu.push({time+1,{nr,nc}});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                return -1;
                }
            }
        }
    return maxtime;

    }
};