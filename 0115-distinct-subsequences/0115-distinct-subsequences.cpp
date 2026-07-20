class Solution {
public:
    int helper(int i,int j,string &s, string& t,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            dp[i][j]=helper(i-1,j-1,s,t,dp)+helper(i-1,j,s,t,dp);
        }
        else{
            dp[i][j]=helper(i-1,j,s,t,dp);
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int ns=s.size();
        int nt=t.size();
        vector<vector<int>>dp(ns,vector<int>(nt,-1));
        return helper(ns-1,nt-1,s,t,dp);
    }
};