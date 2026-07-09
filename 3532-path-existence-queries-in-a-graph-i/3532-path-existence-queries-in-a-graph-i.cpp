class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n,0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[a] > rank[b]) parent[b] = a;
        else { parent[a] = b; rank[b]++; }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                uf.unite(i, i-1);
            }
        }
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(uf.find(q[0]) == uf.find(q[1]));
        }
        return ans;
    }
};