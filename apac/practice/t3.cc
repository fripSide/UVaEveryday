#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

const int maxn = 55;
char mp[105][55];
bool vis[105][105];
bool reach[105][105];
int n, m, l, s;

int go[][2] = {1, 0, 0,1, -1,0, 0,-1};

struct N{
  int x, y;
};

queue<N> Q;

void add(int nx, int ny) {
       N tmp;
            tmp.x = nx;
            tmp.y = ny;
            vis[nx][ny] = true;
            Q.push(tmp);   
}

void BFS() {
    int sum = 0;
    N s;
    s.x = 1;
    s.y = 1;
    Q.push(s);
    while (!Q.empty()) {
        N now = Q.front(); Q.pop();
        reach[now.x][now.y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (vis[nx][ny]) continue;
            if (mp[nx][ny] == '-') continue;
            add(nx, ny);
        }
        for (int i = 1; i < l; ++i) {
            int nx = now.x;
            int ny = now.y + i;
            if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if (vis[nx][ny]) continue;
            if (mp[nx][ny] == '-') continue;
            add(nx, ny);
        }
    }
}

int solve() {
    while(Q.empty() == false) Q.pop();
    BFS();
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
              if (reach[i][j]) ++ans;
        }
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int t = 1; t <= N; ++t) {
        scanf("%d%d%d%d", &n, &m, &l, &s);
        memset(mp, '.', sizeof mp);
        memset(vis, false, sizeof vis);
        memset(reach, false, sizeof reach);
        for (int i = 1; i <= m; ++i)
             scanf("%s", &mp[i][1]);
        printf("Test Case %d: %d\n", t, solve());     
    }
    return 0;     
}
