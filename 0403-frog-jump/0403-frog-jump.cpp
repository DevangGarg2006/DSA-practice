class Solution {
public:
    unordered_set<int>mp;
    unordered_map<long long ,bool>dp;

    bool helper(int idx,int jump,int target){
        if(mp.count(idx)==0) return false;

        if(idx==target)return true;

        long long key = ((long long)idx << 32) | jump;
        if(dp.count(key)) return dp[key];

        bool oneless = false, same = false, onemore = false;

        if(jump > 1) oneless = helper(idx + (jump - 1), jump - 1, target);
        same = helper(idx + jump, jump, target);
        onemore = helper(idx + (jump + 1), jump + 1, target);

        return dp[key] = (oneless || same || onemore);
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();

        
        mp.clear();

        for(int s:stones)mp.insert(s);

        int target=stones.back();

        return helper(1,1,target);
    }
};