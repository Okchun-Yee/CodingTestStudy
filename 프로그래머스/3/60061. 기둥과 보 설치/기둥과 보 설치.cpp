#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> pillar, beam;

int N;

bool DeletePillar(int x, int y){
    // 1. 위 기둥 (x, y+1): 보의 끝 위에 있으면 유지
    if(y + 1 <= N && pillar[x][y + 1]){
        bool ok = (x - 1 >= 0 && beam[x - 1][y + 1])
               || beam[x][y + 1];
        if(!ok) return false;
    }

    // 2. 보 beam[x-1][y+1] (x-1 ~ x): 오른쪽 끝 지지를 잃음
    if(x - 1 >= 0 && y + 1 <= N && beam[x - 1][y + 1]){
        bool ok = pillar[x - 1][y]
               || ((x - 2 >= 0 && beam[x - 2][y + 1]) && beam[x][y + 1]);
        if(!ok) return false;
    }

    // 3. 보 beam[x][y+1] (x ~ x+1): 왼쪽 끝 지지를 잃음
    if(y + 1 <= N && beam[x][y + 1]){
        bool ok = (x + 1 <= N && pillar[x + 1][y])
               || ((x - 1 >= 0 && beam[x - 1][y + 1]) &&
                   (x + 1 <= N && beam[x + 1][y + 1]));
        if(!ok) return false;
    }

    return true;
}

bool DeleteFloor(int x, int y){
    // 1. 기둥 (x, y): 왼쪽 끝 위에 서 있음 → 아래 기둥이나 왼쪽 보의 끝이 필요
    if(pillar[x][y]){
        bool ok = (y - 1 >= 0 && pillar[x][y - 1])
               || (x - 1 >= 0 && beam[x - 1][y]);
        if(!ok) return false;
    }

    // 2. 기둥 (x+1, y): 오른쪽 끝 위에 서 있음 → 아래 기둥이나 오른쪽 보의 끝이 필요
    if(x + 1 <= N && pillar[x + 1][y]){
        bool ok = (y - 1 >= 0 && pillar[x + 1][y - 1])
               || beam[x + 1][y];
        if(!ok) return false;
    }

    // 3. 보 beam[x-1][y] (x-1 ~ x): 오른쪽 이웃이 사라져 양옆 연결 불가 → 한쪽 끝이 기둥 위여야 함
    if(x - 1 >= 0 && beam[x - 1][y]){
        bool ok = (y - 1 >= 0 && pillar[x - 1][y - 1])
               || (y - 1 >= 0 && pillar[x][y - 1]);
        if(!ok) return false;
    }

    // 4. 보 beam[x+1][y] (x+1 ~ x+2): 왼쪽 이웃이 사라져 양옆 연결 불가 → 한쪽 끝이 기둥 위여야 함
    if(x + 1 <= N && beam[x + 1][y]){
        bool ok = (y - 1 >= 0 && pillar[x + 1][y - 1])
               || (x + 2 <= N && y - 1 >= 0 && pillar[x + 2][y - 1]);
        if(!ok) return false;
    }

    return true;
}

bool AddFloor(int x, int y){
    // 1. 설치 위치 아래가 기둥인 경우
    if(y - 1 >= 0 && pillar[x][y - 1]) return true;
    // 2. 설치 위치의 오른쪽 아래가 기둥인 경우
    else if(x + 1 <= N && y - 1 >= 0 && pillar[x + 1][y - 1]) return true;
    // 3. 설치 위치 좌 • 우가 보인 경우
    else if((x + 1 <= N && beam[x + 1][y]) &&
            (x - 1 >= 0 && beam[x - 1][y])) return true;

    return false;
}

bool AddPillar(int x, int y){
    // 1. 설치하려는 곳이 땅인 경우.
    if(y == 0) return true;
    // 2. 설치하려는 곳의 아래가 기둥인 경우 (y ≥ 1 보장)
    else if(pillar[x][y - 1]) return true;
    // 3. 설치하려는 곳의 오른쪽 아래가 보의 한쪽 끝인 경우
    else if((x - 1 >= 0 && beam[x - 1][y])|| beam[x][y]) 
        return true;

    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    N = n;
    
    pillar.assign(n + 1, vector<bool>(n + 1, false));
    beam.assign(n + 1, vector<bool>(n + 1, false));
    
    
    for(auto& q : build_frame){
        int x = q[0], y = q[1], a = q[2], b = q[3];
        if(b == 1){
            if(a == 0 && AddPillar(x, y))     pillar[x][y] = true;
            else if(a == 1 && AddFloor(x, y)) beam[x][y] = true;
        }
        else {
            if(a == 0 && DeletePillar(x, y))     pillar[x][y] = false;
            else if(a == 1 && DeleteFloor(x, y)) beam[x][y] = false;
        }
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(pillar[i][j]){
                answer.push_back({i, j, 0});
            }
            if(beam[i][j]){
                answer.push_back({i, j, 1});
            }
        }
    }
    return answer;
}