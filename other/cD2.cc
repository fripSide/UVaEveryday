#include <cstdio>

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    if (n >= 3 && x >= n - 1 && x <= n + 1) {
        puts("Yes");
        int i = 0;
        int x1 = n - 1, x2 = n + 1;
        if (x == n - 1) {
            x1 = n;
        } else if (x == n + 1) x2 = n;
        printf("%d\n", x1);
        for (i = 2; i <= n - 2; i++)
            printf("%d\n", i);
        printf("%d\n%d\n%d\n", 1, x, 2 * n - 1);
        for (int i = n + 2; i < 2 * n - 1; i++)
            printf("%d\n", i);
        printf("%d\n", x2);
    } else if (n <= 2 && x == n) {
        puts("Yes");
        for (int i = 1; i <= 2 * n - 1; i++)
            printf("%d\n", i);
    } else  puts("No");
    return 0;
}
