#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 6005;
int n;
int tr[maxn], dp[maxn][3];
bool vis[maxn];

void create(int o) {
    vis[o] = true;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && tr[i] == o) {
            create(i);
            dp[o][0] += std::max(dp[i][0], dp[i][1]);
            dp[o][1] += dp[i][0];
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof dp);
        memset(tr, 0, sizeof tr);
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &dp[i][1]);
        int f, c, root;
        root = 0;
        while (scanf("%d%d", &c, &f) != EOF && (c != 0 || f != 0)) {
            tr[c] = f;
            root = f;
        }
        while (tr[root]) root = tr[root];
        create(root);
        int im = std::max(dp[root][0], dp[root][1]);
        printf("%d\n", im);
    }
    return 0;
}
