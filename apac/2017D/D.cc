#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxl = 10005;
const int maxn = 1005;
long long dp[maxl];
int a[maxn], b[maxn], p[maxn];

int main() {
    int T;
    scanf("%d", &T);    
    for (int tCase = 1; tCase <= T; ++tCase) {
        int ans = 0;
        int n, m, l;
        scanf("%d%d%d", &n, &m, &l);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &a[i], &b[i], &p[i]);
            //printf("%d%d%d\n", a[i], b[i], p[i]);
        }
        for (int i = 1; i < maxl; i++) dp[i] = 1e9;
        dp[0] = 0;
        for (int j = 0; j < n; j++) {
            for (int i = l; i >= 1; i--) {
                if (i >= a[j])
                for (int k = i - a[j]; k >= i - b[j]; k--) {
                    if (k >= 0) {
                        dp[i] = min(dp[i], dp[k] + p[j]);
                    }
                }
            }
        }
        printf("Case #%d: ", tCase);
        if (dp[l] <= m) printf("%lld\n", dp[l]);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
