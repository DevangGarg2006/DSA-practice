class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       unordered_map<int,int> freq;
        int l = 0, maxL = 0;

        for(int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;

            
            while(freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }

            maxL = max(maxL, r - l + 1);
        }

        return maxL; 
    }
};