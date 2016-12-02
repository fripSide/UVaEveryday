#include <cstdio>

const int maxn = 100005;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = a[i];
        if (a[t] == i) ans++;
    }
    printf("%d\n", ans / 2);
    return 0;
}
