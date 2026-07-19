class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int> lstIdx(26,-1);

        for(int i=0;i<n;i++){
            lstIdx[s[i]-'a']=i;
        }
        vector<bool> vis(26,false);
        string ans="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(vis[ch-'a']){
                continue;
            }
            while(!ans.empty() && ch<ans.back() &&lstIdx[ans.back() - 'a']>i){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[ch-'a']=true;
        }
        return ans;
    }
};