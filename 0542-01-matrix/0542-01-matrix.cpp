class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
              int m =mat.size();
              int n=mat[0].size();

              queue<pair<pair<int,int>,int>> qu;
              vector<vector<int>> dist(m,vector<int>(n,1e9));
              for(int i=0;i<m;i++){
                 for(int j=0;j<n;j++){
                        if(mat[i][j]==0){
                          qu.push({{i,j},0});
                          dist[i][j]=0;
                        }
                 }
              }

              while(!qu.empty()){
                   int row=qu.front().first.first;
                   int col=qu.front().first.second;
                   int step=qu.front().second;
                   qu.pop();

                   for(int i=0;i<4;i++){
                     int nr=dr[i]+row;
                     int nc=dc[i]+col;
                     if(nr<m && nc<n && nr>=0 && nc>=0){
                        if(dist[nr][nc]>step+1){
                          dist[nr][nc]=step+1;
                            qu.push({{nr,nc},step+1});
                        }
                         
                     }
                   }

              }
    return dist;
    }
};