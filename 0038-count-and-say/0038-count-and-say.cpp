class Solution {
public:
    string countAndSay(int n) {
        string ans="1";

        for(int i=2;i<=n;i++){
            int s=ans.size();
            string curr="";
            int left=0;
            while(left<s){
                int right=left;

                while (right < s && ans[right] == ans[left]) {
                    right++;
                }

                int cnt = right - left;  
                curr += to_string(cnt);
                curr += ans[left];
                left = right;  
            }
            ans=curr;
        }
        return ans;
    }
};