#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2005;

double dp[maxn][maxn];

int main() {
    int T;
    scanf("%d", &T);
    for (int tCase = 1; tCase <= T; tCase++) {
        int N, M;
        scanf("%d %d", &N, &M);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= N; i++) dp[i][0] = 1.0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= min(M, i - 1); j++) {
                dp[i][j] = dp[i][j - 1] * j / (i + j) + dp[i - 1][j] * i / (i + j);
            }
        }
        printf("Case #%d: %.10lf\n", tCase, dp[N][M]);
    }
}
