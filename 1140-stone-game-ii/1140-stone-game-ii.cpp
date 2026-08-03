class Solution {
public:
    int n;
    vector<int> suffixSum;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n) return 0;
        if (2*M >= n - i) return suffixSum[i];
        if (dp[i][M] != -1) return dp[i][M];

        int best = INT_MAX;
        for (int x = 1; x <= 2*M; x++) {
            best = min(best, solve(i + x, max(M, x)));
        }
        return dp[i][M] = suffixSum[i] - best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.assign(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }
        dp.assign(n, vector<int>(n+1, -1));
        return solve(0, 1);
    }
};