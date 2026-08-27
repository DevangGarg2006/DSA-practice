class Solution {
public:
    string lexosmallest(vector<int>& freq) {
        string res = "";

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                res.push_back('a' + i);
                freq[i]--;
            }
        }

        return res;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int n = target.size();
        int matched = 0;

        // Try to match target
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                freq[x]--;
                matched++;
            }
            else {
                // Try making this position greater
                for (int ch = x + 1; ch < 26; ch++) {
                    if (freq[ch] > 0) {
                        string ans = target.substr(0, i);

                        ans += char('a' + ch);
                        freq[ch]--;

                        ans += lexosmallest(freq);

                        return ans;
                    }
                }

                break;
            }
        }

        // Target was completely matched.
        // Need to make it strictly greater by changing
        // some previous position.
        for (int i = matched - 1; i >= 0; i--) {

            // Return target[i] because we are changing it
            freq[target[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest character greater than target[i]
            for (int ch = x + 1; ch < 26; ch++) {
                if (freq[ch] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + ch);
                    freq[ch]--;

                    ans += lexosmallest(freq);

                    return ans;
                }
            }
        }

        return "";
    }
};