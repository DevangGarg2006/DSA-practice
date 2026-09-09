class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1,0);
        vector<int>ans;

        for(int i:nums){
            freq[i]++;
            if(freq[i]==2){
                ans.push_back(i);
            }
        }
        return ans;

    }
};