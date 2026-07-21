class Solution {
public:
    int helper(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
       
        if (i < 0) return j + 1; // need to insert remaining t[0..j]
        if (j < 0) return i + 1; // need to delete remaining s[0..i]

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            
            return dp[i][j] = helper(i - 1, j - 1, s, t, dp);
        } else {
           
            int del = 1 + helper(i - 1, j, s, t, dp);     
            int ins = 1 + helper(i, j - 1, s, t, dp);     
            int rep = 1 + helper(i - 1, j - 1, s, t, dp); 
            return dp[i][j] = min({del, ins, rep});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, word1, word2, dp);
    }
};
