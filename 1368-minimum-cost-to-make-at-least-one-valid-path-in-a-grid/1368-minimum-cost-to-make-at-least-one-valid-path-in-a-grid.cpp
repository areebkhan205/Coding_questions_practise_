class Solution {
   int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
              vector<vector<int>> dist(m,vector<int>(n,1e9));
              dist[0][0]=0;
             deque<pair<int,int>> dq;
             dq.push_back({0,0});
             int cost=0;
             while(!dq.empty()){
                 auto[r,c]=dq.front();
                 dq.pop_front();
                 for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=m || nc>=n || nr<0 || nc<0)continue;
                    int edg=(grid[r][c]==i+1)?0:1;
                   if (dist[r][c] + edg < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + edg;

                    if (edg == 0)
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
                 }
             }
             return dist[m-1][n-1];
    }
};