#include <cstdio>
#include <cstring>


const int maxn = 100005;
double dp[maxn];
double sum[maxn];
double eps = 1e-7;
int n;

double getEps() {
    dp[0] = 0; dp[1] = 1.0; dp[2] = 1.0; dp[3] = 5 / 3.0;
    for (int i = 0; i < 3; i++) sum[i] = i;
    sum[3] = sum[2] + dp[3];
    for (int i = 4; i <= n; i++) {
        dp[i] = 2.0 / i * (1 + dp[i - 2]);
        dp[i] += 2.0 / i * (1 + dp[i - 3]);
        dp[i] += 1.0 / i * (i - 4 + 2 * sum[i -4 ]);
        sum[i] = sum[i - 1] + dp[i];
    }
    return dp[n];
}

int main() {
    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    scanf("%d", &n);
    double res = getEps();
    printf("%.10lf\n", res);
}
