#include <cstdio>
#include <memory.h>

int go[][2] = {1,0, 0,1, -1,0, 0,-1, 1,1, 1,-1, -1,1, -1,-1};
char mp[105][105];
bool mk[105][105];
int n, m;

void dfs(int sx, int sy) {
    for (int i = 0; i < 8; ++i) {
        int nx = sx + go[i][0];
        int ny = sy + go[i][1];
        if (nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }
        if (mk[nx][ny] || mp[nx][ny] != '@') continue;
        mk[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF && n != 0) {
        for (int i = 1; i <= n; ++i) {
            scanf("%s", mp[i] + 1);
        }
        int ans = 0;
        memset(mk, false, sizeof mk);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (mp[i][j] == '@' && !mk[i][j]) {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
