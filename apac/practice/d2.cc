#include <cstdio>
#include <memory.h>

using namespace std;

int n, s;
int A[1005];
long long dp[1005][1005];

// dp[n][sum] = dp[n-1][sum] + dp[n-1][sum-A[n]]
long long dfs(int pos, int cur) {
    if (pos < 0 || cur < 0) return 0;
    if (dp[pos][cur]) return dp[pos][cur];
    dp[pos][cur] = dfs(pos - 1, cur) + dfs(pos - 1, cur - A[pos]);
    return dp[pos][cur];
}

int main(){
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%d", A + i);
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        //dp[i][A[i]] = 1;
    }
    printf("%lld\n", dfs(n, s));
    return 0;
}
