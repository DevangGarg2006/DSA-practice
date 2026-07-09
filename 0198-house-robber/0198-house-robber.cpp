class Solution {
public:
    int helper(int n, vector<int>& dp, vector<int> nums) {
        if (n == 0) {
            return nums[0];
        }
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) return dp[n];
        int rob = nums[n] + helper(n-2, dp, nums);
        int skip = helper(n-1, dp, nums);
        return dp[n] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
          return helper(n-1, dp, nums);
    }
};