#include <cstdio>
#include <algorithm>

const int maxn = 105;
int C, n, m;
int p[maxn], h[maxn], c[maxn];

/*
int solve() {
    int dp[maxn] = {0};
    int mx = 0;
    for (int i = 0; i < m; i++) {
        for (int v = n; v >= p[i]; v--) {
            for (int k = 1; k <= c[i]; k++) {
                if (v >= k * p[i])
                    dp[v] = std::max(dp[v], dp[v - k * p[i]] + k * h[i]);
            }
        }
    }
    return dp[n];
}

int solve() {
    int dp[maxn][maxn] = {0};
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= c[i]; k++)
                if (j >= k * p[i]) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * p[i]] + k * h[i]);
                }
        }
    }
    return dp[m][n];
}*/

int solve() {
    int dp[maxn] = {0}, sum[maxn] = {0};
    for (int i = 1; i <= m; i++) {
        memset(sum, 0, sizeof sum);
        for (int v = p[i]; v <= n; v++) {
            if (dp[v] < dp[v - p[i]] + h[i] && sum[v - p[i]] < c[i]) {
                dp[v] = dp[v - p[i]] + h[i];
                sum[v] = sum[v - p[i]] + 1;
            }
        }
    }
    return dp[n];
}

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d%d%d", &p[i], &h[i], &c[i]);
        //printf("%d %d\n", n, m);
        printf("%d\n", solve());       
    }    
    return 0;
}
