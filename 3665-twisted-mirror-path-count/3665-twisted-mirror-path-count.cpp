class Solution {
public:
    int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[2] = {1, 0};
        int dy[2] = {0, 1};

        // to[i][j][0] = destination after choosing down
        // to[i][j][1] = destination after choosing right
        vector<vector<array<int, 2>>> to(
            m, vector<array<int, 2>>(n, {-1, -1})
        );

        // Precompute reflection destinations
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                for(int d = 0; d < 2; d++) {

                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if(nx >= m || ny >= n) {
                        to[i][j][d] = -1;
                    }
                    else if(grid[nx][ny] == 0) {
                        to[i][j][d] = nx * n + ny;
                    }
                    else {
                        // Mirror reverses the direction
                        to[i][j][d] = to[nx][ny][1-d];
                    }
                }
            }
        }

        // DP
        vector<vector<long long>> dp(
            m, vector<long long>(n, 0)
        );

        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                for(int d = 0; d < 2; d++) {

                    int dest = to[i][j][d];

                    if(dest == -1) continue;

                    int x = dest / n;
                    int y = dest % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m-1][n-1];
    }
};