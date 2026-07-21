class Solution {
public:
    bool safe(string sub){
        int l=0;
        int r=sub.size()-1;
        while(l<r){
            if(sub[l]!=sub[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string>& o,
                int n, int idx, string s) {
        if (idx == n) {
            ans.push_back(o);
            return;
        }
       for(int i=idx;i<n;i++){
        string sub=s.substr(idx,i-idx+1);
        if(safe(sub)){
            o.push_back(sub);
            solve(ans,o,n,i+1,s);
            o.pop_back();
        }
       }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> o;
        int n = s.size();
        solve(ans, o, n, 0, s);
        return ans;
    }
};