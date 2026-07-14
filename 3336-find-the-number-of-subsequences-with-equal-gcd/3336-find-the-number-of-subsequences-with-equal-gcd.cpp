class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n;
    vector<int> nums;

    int dp[201][201][201];
    bool vis[201][201][201];

    int solve(int idx, int g1, int g2) {
        if (idx == n)
            return (g1 > 0 && g1 == g2);

        if (vis[idx][g1][g2])
            return dp[idx][g1][g2];

        vis[idx][g1][g2] = true;

        long long ans = 0;

        // Skip current element
        ans += solve(idx + 1, g1, g2);

        // Put in first subsequence
        ans += solve(idx + 1, std::gcd(g1, nums[idx]), g2);

        // Put in second subsequence
        ans += solve(idx + 1, g1, std::gcd(g2, nums[idx]));

        return dp[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        memset(vis, 0, sizeof(vis));

        return solve(0, 0, 0);
    }
};