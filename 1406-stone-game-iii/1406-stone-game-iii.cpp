class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>&stoneValue,int x){
        if(x>=n) return 0;

        if(dp[x]!=INT_MIN) return dp[x];

        int take=0;
        int best = INT_MIN;
        for(int i=1;i<=3 && x+ i - 1 < n;i++){
            take+=stoneValue[x + i - 1];

           best = max(best, take - solve(stoneValue, i+x ));
        }

        return dp[x]=best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.assign(n,INT_MIN);
        int result=solve(stoneValue,0);

        if(result>0) return "Alice";
        else if(result<0) return "Bob";
        else return "Tie";
    }
};