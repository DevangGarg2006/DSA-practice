class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        long long sum = 0;

        // Step 1: collect non-zero digits
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                digits.push_back(d);
                sum += d;
            }
            n /= 10;
        }

        // Step 2: reverse to restore original order
        reverse(digits.begin(), digits.end());

        // Step 3: build x
        long long x = 0;
        for (int d : digits) {
            x = x * 10 + d;
        }

        return x * sum;
    }
};
