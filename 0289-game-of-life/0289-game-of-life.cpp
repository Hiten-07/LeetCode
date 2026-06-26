class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        // Directions for 8 neighbors
        vector<int> dirs = {-1, 0, 1};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                for (int dx : dirs) {
                    for (int dy : dirs) {
                        if (dx == 0 && dy == 0) continue;
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            // board[x][y] & 1 → original state
                            liveNeighbors += board[ni][nj] & 1;
                        }
                    }
                }
                
                // Apply rules:
                // 2nd bit stores next state
                if ((board[i][j] & 1) && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    board[i][j] |= 2; // cell stays alive
                }
                if (!(board[i][j] & 1) && liveNeighbors == 3) {
                    board[i][j] |= 2; // cell becomes alive
                }
            }
        }
        
        // Update board to next state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1; // shift to next state
            }
        }
    }
};
