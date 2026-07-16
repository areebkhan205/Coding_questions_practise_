class Solution {
public:
    static const int MOD = 1000000007;
    const int NEG = -1000000000;

    pair<int,int> dp[105][105];
    bool vis[105][105];

    pair<int,int> solve(int i, int j, vector<vector<char>> &arr) {

        if(i < 0 || j < 0) return {NEG,0};

        if(arr[i][j] == 'X') return {NEG,0};

        if(i == 0 && j == 0)
            return {0,1};

        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        auto up = solve(i, j-1, arr);
        auto left = solve(i-1, j, arr);
        auto diag = solve(i-1, j-1, arr);

        int best = max({up.first, left.first, diag.first});

        if(best == NEG)
            return dp[i][j] = {NEG,0};

        int ways = 0;

        if(up.first == best)
            ways = (ways + up.second) % MOD;

        if(left.first == best)
            ways = (ways + left.second) % MOD;

        if(diag.first == best)
            ways = (ways + diag.second) % MOD;

        if(arr[i][j] != 'E' && arr[i][j] != 'S')
            best += arr[i][j] - '0';

        return dp[i][j] = {best, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<char>> arr(n, vector<char>(n));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j]=board[i][j];

        memset(vis,false,sizeof(vis));

        auto ans = solve(n-1,n-1,arr);

        if(ans.first < 0)
            return {0,0};

        return {ans.first, ans.second};
    }
};