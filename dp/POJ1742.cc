#include <cstdio>
#include <cstring>

const int maxn = 100005;
int dp[maxn], sum[maxn];
int m, n, pos;
int a[105], c[105];

int solve() {
    int ans = 0;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        memset(sum, 0, sizeof sum);
        for (int v = a[i]; v <= m; v++) {
            if (!dp[v] && dp[v - a[i]] && sum[v - a[i]] < c[i]) {
                dp[v] = 1;
                sum[v] = sum[v - a[i]] + 1;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF && n != 0) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        printf("%d\n", solve());
    }
    return 0;
}
