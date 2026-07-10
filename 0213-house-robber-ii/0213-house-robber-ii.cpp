class Solution {
public:
    int helper(int n, vector<int>& dp, vector<int>& nums) {
        if (n == 0) return nums[0];
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];

        int rob = nums[n] + helper(n-2, dp, nums);
        int notrob = helper(n-1, dp, nums);
        return dp[n] = max(rob, notrob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> dp1(nums1.size(), -1);
        int case1 = helper(nums1.size()-1, dp1, nums1);

        // Case 2: exclude first house
        vector<int> nums2(nums.begin()+1, nums.end());
        vector<int> dp2(nums2.size(), -1);
        int case2 = helper(nums2.size()-1, dp2, nums2);

        return max(case1, case2);
    }
};
