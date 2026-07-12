class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, int n,
               vector<vector<int>>& dp, vector<vector<bool>>& visited) {
        if (j < 0 || j >= n) return INT_MAX;
        if (i == n - 1) return matrix[i][j];

        if (visited[i][j]) return dp[i][j];

        int left  = helper(matrix, i + 1, j - 1, n, dp, visited);
        int same  = helper(matrix, i + 1, j, n, dp, visited);
        int right = helper(matrix, i + 1, j + 1, n, dp, visited);

        visited[i][j] = true;
        return dp[i][j] = matrix[i][j] + min({left, same, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, helper(matrix, 0, j, n, dp, visited));
        }
        return ans;
    }
};
