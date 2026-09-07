class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        const int MOD=1e9+7;
        vector<long long>dp(n+1,0);

        vector<int>lst(26,-1);

        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            int ch=s[i-1]-'a';

            dp[i]=(2*dp[i-1])%MOD;

            if(lst[ch]!=-1){
                dp[i]=(dp[i]-dp[lst[ch]-1]+MOD)%MOD;
            }
            lst[ch]=i;
        }

        return (dp[n]-1+MOD)%MOD;
    }
};