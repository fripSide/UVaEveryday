#include <cstdio>
#include <memory.h>
#include <cmath>

const int maxn = 50000; //46341
int prime[maxn];
bool vis[maxn];

int main() {
    memset(vis, false, sizeof vis);
    int m = (int) sqrt((1 << 31) - 1), t = 0;
    for (int i = 2; i <= m; ++i) {
        if (!vis[i]) {
            prime[t++] = i;
            for (int j = i * i; j < maxn; j += i)
                vis[j] = true;
        }
    }
    //printf("%d  %.3f\n", (1 << 31) - 1, sqrt((long long)1 << 31));    
    int n, c = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) return 0;
        long long sum = 0;
        int num = 0, p = 0;
        while (n > 1 && p < t) {
            if (n % prime[p] == 0) {
                num += 1;
                long long s = 1;
                while (n % prime[p] == 0) {
                    n /= prime[p];
                    s *= prime[p];
                }
                sum += s;
            }
            ++p;
            //printf("%d %d\n", n, prime[p]);
        }
        if (n != 1 || num == 0) {
            num++;
            sum += n;
        }
        if (num == 1) sum += 1;
        printf("Case %d: %lld\n", ++c, sum);
    }
    return 0;
}
