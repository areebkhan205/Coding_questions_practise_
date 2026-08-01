class Solution {
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> qu;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == m - 1 || j == n - 1 || i==0 || j==0) && grid[i][j] == 1) {
                    grid[i][j]=33;
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
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = 33;
                    qu.push({nr,nc});
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};