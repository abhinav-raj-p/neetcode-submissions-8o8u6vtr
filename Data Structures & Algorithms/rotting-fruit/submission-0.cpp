class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // Put all rotten oranges into queue
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int directions[4][2] = {
            {-1, 0},   // up
            {1, 0},    // down
            {0, -1},   // left
            {0, 1}     // right
        };

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process one complete level
            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : directions) {

                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // Check boundaries
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Fresh orange
                    if (grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        // Some fresh oranges couldn't rot
        if (fresh > 0)
            return -1;

        return minutes;
    }
};
