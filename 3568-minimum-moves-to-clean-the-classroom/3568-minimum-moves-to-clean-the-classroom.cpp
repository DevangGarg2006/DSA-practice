class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();       // rows
        int n = classroom[0].size();    // columns

        vector<pair<int, int>> LitterIdx;

        int sti, ste;

        // Find S and all L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'L') {
                    LitterIdx.push_back({i, j});
                }

                if (classroom[i][j] == 'S') {
                    sti = i;
                    ste = j;
                }
            }
        }

        int k = LitterIdx.size();

        // Give each litter an ID
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[LitterIdx[i].first][LitterIdx[i].second] = i;
        }

        // Example: k = 3 -> 111
        int fullMask = (1 << k) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        // row, col, energy, mask, moves
        queue<array<int, 5>> q;

        q.push({sti, ste, energy, 0, 0});

        visited[sti][ste][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            if (mask == fullMask) {
                return moves;
            }

        
            if (e == 0) {
                continue;
            }

        
            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

             
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

               
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                int newe = e - 1;
                int nmask = mask;

              
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

            
                if (classroom[nr][nc] == 'R') {
                    newe = energy;
                }

           
                if (!visited[nr][nc][newe][nmask]) {

                    visited[nr][nc][newe][nmask] = true;

                    q.push({
                        nr,
                        nc,
                        newe,
                        nmask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};