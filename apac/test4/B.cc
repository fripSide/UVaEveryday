#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;
int dp[maxn][maxn][16];

int main() {
    int T;
    scanf("%d", &T);
    for (int tCase = 1; tCase <= T; tCase++) {
        int ans = 0;
        int R, C;
        scanf("%d%d", &R, &C);
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = dp[0][0][2] = dp[0][0][4] = dp[0][0][6] = 1;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dp[i][j][0] = dp[i - 1][j] + 
            }
        }
        printf("Case #%d: %d\n", tCase, ans);
    }
}
