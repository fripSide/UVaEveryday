#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 205;
const int INF = 0xffffff;
int N, T, M1, M2;
int ti[maxn];
int dp[maxn][maxn];
int hasTrain[maxn][maxn][2];

void solve() {
    for (int i = 1; i < N; ++i) dp[T][i] = INF;
    dp[T][N] = 0;
    for (int i = T - 1; i >= 0; --i)
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i + 1][j] + 1;
            if (j < N && hasTrain[i][j][0] && i + ti[j] <= T) dp[i][j] = min(dp[i][j], dp[i + ti[j]][j + 1]);
            if (j > 1 && hasTrain[i][j][1] && i + ti[j - 1] <= T) dp[i][j] = min(dp[i][j], dp[i + ti[j - 1]][j - 1]);
        }
}

int main() {
    int k = 0;
    while (scanf("%d", &N) != EOF && N) {
        memset(ti, 0, sizeof ti);
        memset(dp, 0, sizeof dp);
        memset(hasTrain, 0, sizeof hasTrain);
        scanf("%d", &T);
        for (int i = 1; i < N; ++i) scanf("%d", &ti[i]);
        scanf("%d", &M1);
        int d;
        for (int i = 1; i <= M1; ++i) {
            scanf("%d", &d);
            for (int j = 1; j < N; ++j) {
                if (d <= T) hasTrain[d][j][0] = 1;
                d += ti[j];
            }
        }
        scanf("%d", &M2);
        for (int i = 1; i <= M2; ++i) {
            scanf("%d", &d);
            for (int j = N - 1; j >= 1; --j) {
                if (d <= T) hasTrain[d][j + 1][1] = 1;
                d += ti[j];
            }
        }
        solve();
        printf("Case Number %d: ", ++k);
        if (dp[0][1] >= INF) puts("impossible");
        else printf("%d\n", dp[0][1]);
    }
    return 0;
}
