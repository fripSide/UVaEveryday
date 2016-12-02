#include <cstdio>

const int maxn = 100005;
char buf[maxn];
int n, a, b;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", buf);
    int sa = 0, sb = 0;
    for (int i = 0; i < n; ++i) {
        if (buf[i] == 'c') puts("No");
        else if (buf[i] == 'a') {
            if (sa + sb < a + b) {
                puts("Yes");
                ++sa;
            } else puts("No");
        } else {
            if (sb < b && sa + sb < a + b) {
                puts("Yes");
                ++sb;
            } else puts("No");
        }
    }
    return 0;
}
