class Solution {
public:
    void helper(vector<int>& nums, int start, int remain, vector<int>& o, vector<vector<int>>& ans){
        if(remain==0){
            ans.push_back(o);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>remain) break;

             o.push_back(nums[i]);
            helper(nums, i+1, remain - nums[i], o, ans); // move forward (no reuse)
            o.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> o;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates, 0, target, o, ans);
        return ans;
    }
};