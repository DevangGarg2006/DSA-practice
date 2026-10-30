class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        // Starting node has frequency 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){

            auto [cost,node,freq]=pq.top();
            pq.pop();

            if(cost!=dist[node][freq]){
                continue;
            }

            if(node==n-1){
                return cost;
            }

            for(auto &[v,wt]:adj[node]){
                int newF;

                if(labels[node]==labels[v]){
                    newF=freq+1;
                }
                else{
                    newF=1;
                }

                if(newF>k){
                    continue;
                }

                int newC=cost+wt;

                if(newC< dist[v][newF]) {
                    dist[v][newF] = newC;
                    pq.push({newC, v, newF});
                }
            }
        }
        return -1;
    }
};