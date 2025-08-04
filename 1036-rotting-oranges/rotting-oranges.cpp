class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = 0;
        int cnt = 0, days = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] != 0)
                    total++;
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!q.empty()) {
            int k = q.size();
             cnt += k;
            while (k--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                        grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if (!q.empty())
                days++;
        }
        return total == cnt ? days : -1;
    }
};