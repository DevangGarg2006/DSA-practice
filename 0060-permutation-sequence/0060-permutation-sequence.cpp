class Solution {
public:
    string getPermutation(int n, int k) {
        string num="";
        for(int i=1;i<=n;i++){
            num+=to_string(i);
        }
        vector<int>fac(n+1,1);
        for(int i=1;i<=n;i++){
            fac[i]=fac[i-1]*i;
        }
        k--;

        string ans="";
        for(int i=n;i>=1;i--){
            int idx=k/fac[i-1];
            ans += num[idx];
            num.erase(num.begin() + idx);
            k %= fac[i-1];
        }
        return ans;
    }
};