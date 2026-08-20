class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return nums; // trivial case

        // arr1 starts with nums[0], arr2 with nums[1]
        vector<int> arr1{nums[0]};
        vector<int> arr2{nums[1]};

        // distribute remaining elements
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // build result directly
        vector<int> result;
        result.reserve(n);
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());

        return result;
    }
};
