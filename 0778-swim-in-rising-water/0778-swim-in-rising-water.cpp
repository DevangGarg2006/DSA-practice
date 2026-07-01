
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }
    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int s=grid.size();
        vector<pair<int,int>> cells;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                cells.push_back({grid[i][j],i*s+j});
            }
        }

        sort(cells.begin(),cells.end());
        DSU dsu(s*s);
        vector<bool> active(s*s, false);
        vector<int> dir = {0,1,0,-1,0};

        for (auto &p : cells) {
            int ele=p.first;
            int node=p.second;
            int r = node / s, c = node % s;
            active[node] = true;
             for (int k = 0; k < 4; k++) {
                int nr = r + dir[k], nc = c + dir[k+1];
                 if (nr >= 0 && nr < s&& nc >= 0 && nc < s) {
                    int nid = nr * s + nc;
                    if (active[nid]) {
                        dsu.unite(node, nid);
                    }
                }
             }
             if (dsu.find(0) == dsu.find(s*s - 1)) {
                return ele;
            }
        }
        return -1;
    }
};