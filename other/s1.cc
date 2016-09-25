#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

//http://ac.jobdu.com/problem.php?pid=1456

int mp[55][55][55];
bool mk[55][55][55];
struct N {
    int x, y, z;
    int t;   
};

queue<N> Q;
int go[6][3] = {0,0,1, 1,0,0, 0,1,0, -1,0,0, 
        0,-1,0, 0,0,-1};
int A, B, C, T;
int BFS() {
    memset(mk, false, sizeof mk);
    while (!Q.empty()) Q.pop();
    N start = {1, 1, 1, 0};
    Q.push(start);
    while (!Q.empty()) {
        N now = Q.front(); Q.pop();
        if (now.x == A && now.y == B && now.z == C && now.t <= T) return now.t; 
        for (int i = 0; i < 6; ++i) {
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2];
            if (nx < 1 || nx > A || ny < 1 || ny > B || nz < 1 || nz > C) continue;
            if (mp[nx][ny][nz] == 1 || mk[nx][ny][nz]) continue;
            mk[nx][ny][nz] = true;
            N tmp;
            tmp.x = nx, tmp.y = ny, tmp.z = nz;
            tmp.t = now.t + 1;
            Q.push(tmp);
        }
    }
    return -1;
}

int main() {
    int K;
    scanf("%d", &K);    
    while (K--) {
        scanf("%d%d%d%d", &A, &B, &C, &T);
        for (int i = 1; i <= A; ++i) {
            for (int j = 1; j <= B; ++j) {
                for (int k = 1; k <= C; ++k) {
                    scanf("%d", &mp[i][j][k]);
                }            
            }
        }
        int ans = BFS();
        printf("%d\n", ans);
    }
    return 0;
}
