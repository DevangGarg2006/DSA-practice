class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int sg=g.size();
        int ss=s.size();
        int i=0,j=0;
        while(i<sg && j<ss){
            if(s[j]>=g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};