class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

    if (m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        vector<vector<int>> dist(m,vector<int>(n,1e9));

          dist[0][0]=0;

          priority_queue<
             pair<int,pair<int,int>>,
             vector<pair<int,pair<int,int>>>,
             greater<pair<int,pair<int,int>>>
          > pq;
          
          pq.push({0,{0,0}});
          int timecol=INT_MAX;
          while(!pq.empty()){
            auto[time,cell]=pq.top();
            pq.pop();

         
                timecol=min(time,timecol);
            int r=cell.first;
            int c=cell.second;
            if(r==m-1 && c==n-1)return time;
               if(time>dist[r][c])continue;
            for(int i=0;i<4;i++){
                   int nr=dr[i]+r;
                   int nc=dc[i]+c;
                   if(nr<0 || nr>=m || nc<0 || nc>=n )continue;
                    int newtime;
                        if(grid[nr][nc]<=time+1){
                             newtime=time+1;
                        }
                        else{
                            int diff=grid[nr][nc]-time;
                            if(diff%2==0){
                                  newtime=grid[nr][nc]+1;
                            }
                            else{
                                newtime=grid[nr][nc];
                            }
                        }
                            if (newtime < dist[nr][nc]) {
                    dist[nr][nc] = newtime;
                    pq.push({newtime, {nr, nc}});
                }
                   
            }

          }
    return -1;
        
    }
};