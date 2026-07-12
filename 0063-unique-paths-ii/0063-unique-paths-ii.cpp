class Solution {
public:
    int helper(vector<vector<int>> &dp,int m,int n,int i,int j,vector<vector<int>>& obstacleGrid){
        if (i >= m || j >= n) return 0;


        if (obstacleGrid[i][j] == 1) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = helper(dp, m, n, i + 1, j, obstacleGrid) +
                          helper(dp, m, n, i, j + 1, obstacleGrid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return helper(dp,m,n,0,0,obstacleGrid);
    }
};