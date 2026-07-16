class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefMax(n, LLONG_MIN);
        vector<long long> preGcd(n);   

        prefMax[0] = nums[0];
        preGcd[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], (long long)nums[i]);
            preGcd[i] = gcd(nums[i], prefMax[i]);
        }

        sort(preGcd.begin(), preGcd.end());

        int l = 0;
        int r = preGcd.size() - 1;
        long long sum = 0;

        while (l < r) {
            sum += gcd(preGcd[l], preGcd[r]);
            l++;
            r--;
        }

        return sum;
    }
};
