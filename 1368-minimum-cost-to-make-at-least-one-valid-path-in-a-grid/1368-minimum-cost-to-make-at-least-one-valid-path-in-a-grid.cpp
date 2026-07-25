class Solution {
   int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
              vector<vector<int>> dist(m,vector<int>(n,1e9));
              dist[0][0]=0;
             priority_queue<
              pair<int,pair<int,int>>,  // cost (i,j)  the cost to reach i and j  and min heap top min cist
              vector< pair<int,pair<int,int>>>,
              greater< pair<int,pair<int,int>>>
             >  pq;
             pq.push({0,{0,0}});

             while(!pq.empty()){
                auto[cost,cell]=pq.top();
                  pq.pop();
                  int r=cell.first;
                  int  c=cell.second;

                  if(cost>dist[r][c])continue;
              
                  

                for(int i=0;i<4;i++){
                       int nr=r+dr[i];
                       int nc=c+dc[i];

                       if(nr<0 || nr>=m || nc<0 || nc>=n)continue;

                       int  newcost=(grid[r][c]==i+1)?0:1;  //if  same cell as the direction else change it to 1

                       if(dist[r][c]+newcost<dist[nr][nc]){
                          dist[nr][nc]=dist[r][c]+newcost;
                          pq.push({dist[nr][nc],{nr,nc}});
                       }
                }
             }
    return dist[m-1][n-1];

    }
};