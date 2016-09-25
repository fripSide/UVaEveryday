#include <cstdio>

const int maxn = 1005;
typedef unsigned long long ULL;
int f[maxn][maxn * 3], period[maxn];

int pow_mod(ULL a, ULL b, int n) {
    if (!b) return 1;
    int k = pow_mod(a, b/2, n);
    k = k * k % n;
    if (b % 2) k = k * a % n;
    return k;
}

int solve(ULL a, ULL b, int n) {
    if (a == 0 || n == 1) return 0;
    int p = pow_mod(a % period[n], b, period[n]);
    return f[n][p];
}

int main() {
    for (int n = 2; n <= 1000; n++) {
        f[n][0] = 0; f[n][1] = 1;
        for (int i = 2; ; i++) {
            f[n][i] = (f[n][i - 1] + f[n][i-2]) % n;
            if (f[n][i - 1] == 0 && f[n][i] == 1) {
                period[n] = i - 1;
                break;
            }
        }
    }
    int c, n;
    ULL a, b;
    scanf("%d", &c);
    while (c--) {
        scanf("%llu%llu%d", &a, &b, &n);
        //printf("%llu %llu\n", a, b);
        printf("%d\n", solve(a, b, n));
    }      
    return 0;
}
