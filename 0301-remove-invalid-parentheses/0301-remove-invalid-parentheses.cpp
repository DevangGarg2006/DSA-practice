
class Solution {
public:
    void solve(int i, int op, int cl, string o, int open,
               vector<string>& ans, string& s) {
        
        if (i == s.size()) {
            if (op == 0 && cl == 0 && open == 0) {
                ans.push_back(o);
            }
            return;
        }

        if (s[i] == '(') {
            // Remove '('
            if (op > 0) {
                solve(i + 1, op - 1, cl, o, open, ans, s);
            }

            // Keep '('
            solve(i + 1, op, cl, o + s[i], open + 1, ans, s);
        }
        else if (s[i] == ')') {
            // Remove ')'
            if (cl > 0) {
                solve(i + 1, op, cl - 1, o, open, ans, s);
            }

            // Keep ')' only if matched
            if (open > 0) {
                solve(i + 1, op, cl, o + s[i],
                      open - 1, ans, s);
            }
        }
        else {
            solve(i + 1, op, cl, o + s[i], open, ans, s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int op = 0, cl = 0;

        for (char c : s) {
            if (c == '(') {
                op++;
            }
            else if (c == ')') {
                if (op > 0) {
                    op--;
                }
                else {
                    cl++;
                }
            }
        }

        vector<string> ans;
        solve(0, op, cl, "", 0, ans, s);

        // Remove duplicate results
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};
