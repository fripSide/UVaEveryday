#include <cstdio>
#include <algorithm>
#include <cstring>

int n, m, k;

const int maxn = 55;
int a[maxn][maxn], b[maxn][maxn];
long long ans[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                ans[i][l] += a[i][j] * b[j][l]; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (j != k - 1) {
                printf("%lld ", ans[i][j]);
            } else printf("%lld\n", ans[i][j]);
        }
    }
    return 0;
}
