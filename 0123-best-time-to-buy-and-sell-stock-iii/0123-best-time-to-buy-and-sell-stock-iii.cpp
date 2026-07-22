class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;

        int k = 2;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int t = 0; t <= k; t++) {
            dp[0][t][0] = 0;          // not holding on day 0
            dp[0][t][1] = -prices[0]; // holding on day 0 (buy)
        }

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= k; t++) {
                dp[i][t][0]=max(dp[i-1][t][0],dp[i-1][t][1]+prices[i]);
                dp[i][t][1]=max(dp[i-1][t][1],dp[i-1][t-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0]; 
    }

}
;