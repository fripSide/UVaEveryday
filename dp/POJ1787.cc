#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10005;
int D[4] = {1, 5, 10, 25};
int path[maxn][maxn];

int main() {
    int P, C[4];
    int dp[maxn];
    while (scanf("%d%d%d%d%d", &P, &C[0], &C[1], &C[2], &C[3]) != EOF && !(P == 0 && C[0] == 0 && C[1] == 0)) {
        memset(dp, 0, sizeof dp);
        // dp[0] = 1;
        for (int j = 0; j <= P; j++)
        for (int t = 0; t < 4; t++) {
            // for (int j = D[t]; j <= P; j++) {
                for (int k = 1; k <= C[t]; k++) {
                    if (j >= k * D[t]) {
                        dp[j] = max(dp[j], dp[j - k * D[t]] + k);
                    }
                }
            //}
        }
        for (int i = 0; i <= P; i++) printf("%d%c", dp[i], " \n"[i == P]);
        printf("P=%d %d\n", P, dp[P]);
    }
    return 0;
}
