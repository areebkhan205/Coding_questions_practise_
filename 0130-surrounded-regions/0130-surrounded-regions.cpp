class Solution {
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};


public:
    void solve(vector<vector<char>>& b) {
 
        int m = b.size();
        int n =b[0].size();
        queue<pair<int, int>> qu;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == m - 1 || j == n - 1 || i==0 || j==0) && b[i][j]=='O') {
                    b[i][j]='A';
                    qu.push({i, j});
                }
            }
        }

        while (!qu.empty()) {
            auto [row, col] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nc >= 0 && nr <= m - 1 && nc <= n - 1 &&
                    b[nr][nc] == 'O') {
                    b[nr][nc] = 'A';
                    qu.push({nr,nc});
                }
            }
        }

          for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(b[i][j]=='O')b[i][j]='X';
            }
        }
            

                for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(b[i][j]=='A')b[i][j]='O';
            }
        }
    }
};