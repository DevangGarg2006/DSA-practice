class disjointset {
    public:
    vector<int> parent, size;
    disjointset(int n) {
        parent.resize(n);
        size.resize(n, 1) ;
         for (int i = 0; i < n; i++) { parent[i] = i; }
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unionbysize(int a, int b) {
        int pu = find(a);
        int pv = find(b);
        if (pv == pu)
            return;

        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
    }
     int getSize(int x) {
        return size[find(x)];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int s=grid.size();
        disjointset dsu(s*s);
       vector<int> dirn = {0,1,0,-1,0};
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(grid[i][j]==1){
                    int id=i*s+j;
                    for(int d=0;d<4;d++){
                        int r=i+dirn[d];
                        int c=j+dirn[d+1];
                        if (r >= 0 && r < s && c >= 0 && c < s && grid[r][c] == 1) {
                            dsu.unionbysize(id,r*s+c);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int r=0;r<s;r++){
            for(int c=0;c<s;c++){
                if(grid[r][c]==0){
                   unordered_set<int> seen;
                    int potential=1;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dirn[k], nc = c + dirn[k+1];
                        if (nr >= 0 && nr < s && nc >= 0 && nc < s && grid[nr][nc] == 1) {
                            int root = dsu.find(nr * s + nc);
                            if (!seen.count(root)) {
                                potential += dsu.size[root];
                                seen.insert(root);
                            }
                        }
                    }
                    ans = max(ans, potential);
                }
            }
        }
        for (int i = 0; i < s*s; i++) {
            if (grid[i/s][i%s] == 1) {
                ans = max(ans, dsu.getSize(i));
            }
        }

        return ans;
    }
};