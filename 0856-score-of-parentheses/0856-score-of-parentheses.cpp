class Solution {
public:
    int solve(string& s, int& i) {
        int cnt = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                i++;

                if (s[i] == ')') {
                    cnt++;
                    i++;
                } else {
                    int inner = solve(s, i);
                    cnt += 2 * inner;
                }
            }
            else{
                i++;
                return cnt;
            }
        }
        return cnt;
    }
    int scoreOfParentheses(string s) {
        int i = 0;
        return solve(s, i);
    }
};