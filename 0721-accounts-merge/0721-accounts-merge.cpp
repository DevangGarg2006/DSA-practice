class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Build graph
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;

        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = name;
                if (i == 1)
                    continue;
                graph[acc[1]].push_back(acc[i]);
                graph[acc[i]].push_back(acc[1]);
            }
        }

        // BFS to collect connected emails
        unordered_set<string> visited;
        vector<vector<string>> result;

        for (auto& acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (visited.count(email))
                    continue;

                vector<string> component;
                queue<string> q;
                q.push(email);
                visited.insert(email);

                while (!q.empty()) {
                    string node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (auto& nei : graph[node]) {
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }

                sort(component.begin(), component.end());
                component.insert(component.begin(), emailToName[email]);
                result.push_back(component);
            }
        }
        return result;
    }
};
