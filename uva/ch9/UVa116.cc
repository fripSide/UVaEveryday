#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 102;
const int INF = 0xffffff;
int dis[maxn][maxn], mp[maxn][maxn], m, n;

int turn(int x) {
    if (x == 0) return m;
    if (x == m + 1) return 1;
    return x;
}

int dfs(int x, int y) {
    x = turn(x);
    if (dis[x][y] != -INF) return dis[x][y];
    return dis[x][y] = mp[x][y] + min(min(dfs(x - 1, y + 1), dfs(x, y + 1)), dfs(x + 1, y + 1));
}

void path(int x, int y) {
    if (y < n) printf("%d ", x);
    else {
        printf("%d\n", x);
        return;
    }
    int r[3] = {turn(x - 1), turn(x), turn(x + 1)};
    sort(r, r + 3);
    int tt = dis[x][y] - mp[x][y];
    if (tt == dis[r[0]][y + 1]) path(r[0], y + 1);
    else if (tt == dis[r[1]][y + 1]) path(r[1], y + 1);
    else path(r[2], y + 1);
}

int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &mp[i][j]);
                if (j == n) dis[i][j] = mp[i][j];
                else dis[i][j] = -INF;
            }
        int mi = INF, t, rx;
        for (int i = 1; i <= m; ++i) {
            t = dfs(i, 1);
            if (t < mi) rx = i, mi = t;
        }
        path(rx, 1);
        printf("%d\n", mi);
    }
    return 0;
}
