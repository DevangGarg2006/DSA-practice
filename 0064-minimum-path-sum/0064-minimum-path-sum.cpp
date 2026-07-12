class Solution {
public:
    int helper(vector<vector<int>>& dp, vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) return INT_MAX;

        if (i == m - 1 && j == n - 1) return grid[i][j];


        if (dp[i][j] != -1) return dp[i][j];

        int down = helper(dp, grid, i + 1, j);
        int right = helper(dp, grid, i, j + 1);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(dp, grid, 0, 0);
    }
};