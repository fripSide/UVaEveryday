#include <cstdio>
#include <memory.h>
#include <cmath>

const int maxn = 10000;
int t, prime[maxn], e[maxn];

void add_integer(int n, int d) {
    for (int i = 0; i < t; ++i) {
        while (n % prime[i] == 0) {
            n /= prime[i];
            e[i] += d;
        }
        if (n == 1) break;
    }
}

void add_factorial(int n, int d) {
    for (int i = 1; i <= n; ++i) {
        int m = i;
        //add_integer(i, d);
        for (int j = 0; j < t; ++j) {
            while (m % prime[j] == 0) {
                m /= prime[j];
                e[j] += d;
            }
            if (m == 1) break;
        }
    }
}

int main() {
    int m = sqrt(maxn);
    t = 0;
    bool vis[maxn];
    memset(vis, false, sizeof vis);
    for (int i = 2; i <= m; ++i) {
        if (!vis[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                vis[j] = true;
            }
        }
    }
    for (int i = 2; i <= maxn; ++i)
        if (!vis[i]) {
            prime[t++] = i;
            // printf("%d ", prime[t-1]);
        }
    int p, q, r, s;
    while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
        memset(e, 0, sizeof e);
        add_factorial(p, 1);
        add_factorial(q, -1);
        add_factorial(p - q, -1);
        add_factorial(r, -1);
        add_factorial(s, 1);
        add_factorial(r - s, 1);
        double ans = 1;
        for (int i = 0; i < t; ++i) {
            if (e[i] != 0) {
               // printf("%d ^ %d\n", prime[i], e[i]);
            }
            ans *= pow(prime[i], e[i]);
        }
        printf("%.5lf\n", ans);
    }
    //printf("\n%d\n", t);
    return 0;
}
