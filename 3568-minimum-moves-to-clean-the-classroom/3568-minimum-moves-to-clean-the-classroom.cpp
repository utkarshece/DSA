class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // litter cell ko ek unique number denge
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Start aur litter positions find karo
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                else if(classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // Agar litter hi nahi hai
        if(litterCount == 0)
            return 0;

        /*
            visited[row][col][energy][mask]

            mask:
            1 = litter abhi collect nahi hua
            0 = litter collect ho gaya
        */

        int totalMasks = 1 << litterCount;

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        // Initially saare litter pending hain
        int startMask = totalMasks - 1;

        queue<tuple<int,int,int,int>> q;

        // row, col, energy, mask
        q.push({sr, sc, energy, startMask});

        visited[sr][sc][energy][startMask] = true;

        // 4 directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty()) {

            int size = q.size();

            // Current BFS level
            while(size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // Saara litter collect ho gaya
                if(mask == 0)
                    return moves;

                // Energy khatam hai
                if(currEnergy == 0)
                    continue;

                // 4 possible directions
                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Boundary check
                    if(nr < 0 || nr >= m ||
                       nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if(classroom[nr][nc] == 'X')
                        continue;

                    // Normal move -> energy - 1
                    int newEnergy = currEnergy - 1;

                    // R par energy full reset
                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    // Agar litter mila
                    if(classroom[nr][nc] == 'L') {

                        int idx = id[nr][nc];

                        // Is litter ko collected mark karo
                        newMask &= ~(1 << idx);
                    }

                    // Agar ye state pehle visit nahi hui
                    if(!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};