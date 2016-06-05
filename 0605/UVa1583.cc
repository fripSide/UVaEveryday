#include <cstdio>
#include <memory.h>

const int maxn = 100001;
int ans[maxn];

void calc() {
    memset(ans, 0, sizeof ans);
    for (int m = 1; m < maxn; ++m) {
        int x = m, y = m;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || m < ans[y]) ans[y] = m;
    }
}

int main() {
    int n;
    calc();
    scanf("%d", &n);
    while (n--) {
        int d;
        scanf("%d", &d);
        printf("%d\n", ans[d]);
    }
    return 0;
}
