class DisjointSet{
        public: 
        vector<int> parent,rank;
        DisjointSet(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUparent(int n){
            if(parent[n]==n){
                return n;
            }
            return parent[n]=findUparent(parent[n]);
        }
        void unionByRank(int u, int v) {
        int pu = findUparent(u);
        int pv = findUparent(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // not enough edges

        DisjointSet ds(n);

        // Union all connections
        for (auto &edge : connections) {
            ds.unionByRank(edge[0], edge[1]);
        }

        // Count number of components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUparent(i) == i) components++;
        }

        // To connect components, need (components - 1) operations
        return components - 1;
    }
};