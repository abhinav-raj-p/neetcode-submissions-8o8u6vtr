class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        // Out of bounds
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size()) {
            return;
        }

        // Water or already visited
        if (grid[r][c] == '0') {
            return;
        }

        // Mark visited
        grid[r][c] = '0';

        // Explore 4 directions
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == '1') {

                    count++;

                    // Explore entire island
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};