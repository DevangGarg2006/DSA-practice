class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<pair<int,int>>mp;

        for(int i=0;i<n;i++){
            mp.push_back({nums[i],i});
        }

        sort(mp.begin(),mp.end());

        int start=0;

        while(start<n){
            int end=start;

            while(end+1<n && mp[end+1].first-mp[end].first<=limit){
                    end++;
            }

            vector<int>idx;

            for(int i=start;i<=end;i++){
                idx.push_back(mp[i].second);
            }

            sort(idx.begin(), idx.end());

            for (int i = 0; i < idx.size(); i++) {
                nums[idx[i]] = mp[start + i].first;
            }

            start=end+1;
        }
        return nums;
    }
};