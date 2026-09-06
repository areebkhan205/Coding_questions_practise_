class Solution {
    int dr[4]={0,1,0,-1};
    int dc[4]={-1,0,1,0};
public:
    void solve(vector<vector<char>>& board) {
          int  m=board.size();
          int n=board[0].size();
            queue<pair<int,int>> qu;

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                     if((i==m-1 || j==n-1 ||  i==0 || j==0) && board[i][j]=='O'){
                        board[i][j]='A';
                         qu.push({i,j});
                     }
                }
            }
            while(!qu.empty()){
                 int row=qu.front().first;
                 int col=qu.front().second;
                  

                  qu.pop();

                  for(int i=0;i<4;i++){
                      int nr=dr[i]+row;
                      int nc=dc[i]+col;


                      if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc]=='O'){
                          board[nr][nc]='A';
                          qu.push({nr,nc});
                      }
                  }
            }

             for(int i=0;i<m;i++){
                 for(int j=0;j<n;j++){
                      if(board[i][j]=='O'){
                           board[i][j]='X';
                      }
                 }
             }
               for(int i=0;i<m;i++){
                 for(int j=0;j<n;j++){
                      if(board[i][j]=='A'){
                           board[i][j]='O';
                      }
                 }
             }
    }
};