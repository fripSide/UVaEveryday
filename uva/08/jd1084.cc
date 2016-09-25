#include <cstdio>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int buf1[12], buf2[12], s1 = 0, s2 = 0;
        while (a != 0) {
            buf1[s1++] = a % 10;
            a /= 10;
        }
        while (b != 0) {
            buf2[s2++] = b % 10;
            b /= 10;
        }
        int ans = 0;
        for (int i = 0; i < s1; ++i) {
            for (int j = 0; j < s2; ++j) {
                ans += buf1[i] * buf2[j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
