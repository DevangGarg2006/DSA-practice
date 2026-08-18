class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);

      
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<bool> inMST(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        pq.push({0, 0}); 
        int mst_cost = 0;
       

        while (!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;

            inMST[u] = true;
            mst_cost += w;
          

            for (auto &[v, wt] : adj[u]) {
                if (!inMST[v]) pq.push({wt, v});
            }
        }
        return mst_cost;
    }
};