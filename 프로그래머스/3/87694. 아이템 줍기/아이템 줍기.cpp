#include <string>
#include <vector>
#include <queue>

using namespace std;
int map[102][102];
int dist[102][102];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void fillmap(vector<vector<int>>& rectangle) {
    for (auto& r : rectangle) {
        int x1 = r[0]*2, y1 = r[1]*2, x2 = r[2]*2, y2 = r[3]*2;

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                // border 판정
                bool edge = (i == x1 || i == x2 || j == y1 || j == y2);

                if (edge) {
                    if (map[i][j] != 2) map[i][j] = 1;
                } else {
                    map[i][j] = 2;
                }
            }
        }
    }
}


int bfs(int sx, int sy, int gx, int gy)
{
    queue<pair<int, int>> que;
    que.push({sx, sy});
    dist[sx][sy] = 1;

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if (x == gx && y == gy)
        {
            return (dist[x][y] - 1) / 2;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 102 && ny >= 0 && ny < 102)
            {
                if (map[nx][ny] == 1 && dist[nx][ny] == 0)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    fillmap(rectangle);
    int answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);

    return answer;
}