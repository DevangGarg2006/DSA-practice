class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || K == 0) return 0;

        // Unlimited transactions case
        if (K >= n/2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
            }
            return profit;
        }

        // DP arrays: dp[t][0] = not holding, dp[t][1] = holding
        vector<vector<int>> dp(K+1, vector<int>(2, 0));
        for (int t = 0; t <= K; t++) {
            dp[t][0] = 0;
            dp[t][1] = -prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= K; t++) {
                dp[t][0] = max(dp[t][0], dp[t][1] + prices[i]);       // sell
                dp[t][1] = max(dp[t][1], dp[t-1][0] - prices[i]);     // buy
            }
        }

        return dp[K][0];
    }
};
