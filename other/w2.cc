#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const int maxm = 105;
int p[maxn], dp[maxn][maxm][2];
bool vis[maxn];

int N, M;
vector<int> G[maxn];

void treedp(int i, int f) {
    if (vis[i]) return;
    int cnt = G[i].size();
    vis[i] = true;
    dp[i][0][1] = p[i];
    for (int u = 0; u < cnt; ++u) {
        int v = G[i][u];
        if (v != f) {
            treedp(v, i);
            for (int i1 = 1; i1 <= M; ++i1) {
                dp[i][i1][0] += dp[v][i1][1];
                dp[i][i1][1] += max(dp[v][i1 - 1][0], dp[v][i1 - 1][1]); 
            }
        }
        printf("calc u=%d v=%d f=%d pu=%d\n", i, v, f, p[i]);
    } 
}

int main() {
    memset(dp, 0, sizeof dp);
    memset(vis, false, sizeof vis);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &p[i]);
    for (int i = 1; i < N; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        //printf("u=%d v=%d\n", a, b);
    }
    for (int i = 1; i <= N; ++i)
    //for (int j = 0; j <= M; ++j)
    //    dp[i][j][1] = p[i];
    treedp(1, 0);
    printf("%d\n", max(dp[1][M][0], dp[1][M][1]));
    /*for (int i = 1; i <= N; ++i) {
        printf("n=%d v=%d\n", i, max(dp[i][M][0], dp[i][M][1]));
    }*/
    return 0;
}
