class Solution {
public:
    void dfs(int idx, vector<bool>& visited, vector<vector<int>>& adj, int &vert, int &edg) {
        visited[idx] = true;
        vert++;
        for (int i : adj[idx]) {
            edg++;  // count edge occurrence
            if (!visited[i]) {
                dfs(i, visited, adj, vert, edg);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {   // use auto& instead of int
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vert = 0;
                int edg = 0;
                dfs(i, visited, adj, vert, edg);

                // each edge counted twice in adjacency list
                edg /= 2;

                int m = (vert * (vert - 1)) / 2;  // edges in complete graph
                if (m == edg) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
