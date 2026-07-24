class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXors;
        unordered_set<int> uniqueXors;

         unordered_set<int> vals(nums.begin(), nums.end());
        vector<int> v(vals.begin(), vals.end());
        int m = v.size();

        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                pairXors.insert(v[i] ^ v[j]);
            }
        }

        for (int x : pairXors) {
            for (int c : v) {
                uniqueXors.insert(x ^ c);
            }
        }

         return uniqueXors.size();
    }
};