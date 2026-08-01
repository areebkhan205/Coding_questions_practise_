class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> dist(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
       queue<pair<pair<int,int>,int>> qu;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(mat[i][j]==0){
                    vis[i][j]=1;
                    qu.push({{i,j},0});
                 }
            }
        }
        while(!qu.empty()){
         auto[cell,step]=qu.front();

               dist[cell.first][cell.second]=step;
         qu.pop();
         for(int i=0;i<4;i++){
            int nr=dr[i]+cell.first;
            int nc=dc[i]+cell.second;
            if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                   qu.push({{nr,nc},step+1});
            }
         }
        }
    return dist;

    }
};