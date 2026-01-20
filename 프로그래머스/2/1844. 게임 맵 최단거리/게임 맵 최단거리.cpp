    #include<vector>
    #include <queue>
    #include <iostream>
    using namespace std;

    int dx[] = { -1, 1, 0, 0 };	// row 이동
    int dy[] = { 0, 0, -1, 1 };	// col 이동
    int dist[101][101];
    bool visited[101][101] = { false };

    int solution(vector<vector<int> > maps)
    {
        int n = maps.size();
        int m = maps[0].size();
        queue<pair<int, int>> q;
        
        visited[0][0] = true;
        q.push({ 0,0 });
        dist[0][0]++;


        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            if (x == n - 1 && y == m - 1) {
                return dist[n-1][m-1];
            }

            if (maps[x][y] == 0) continue;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (maps[nx][ny] == 1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({ nx, ny });
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
        }
        return -1;
    }