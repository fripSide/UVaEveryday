#include <cstdio>

int main() {
    int n, X[1005];
    const int mod = 10001;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &X[i]);
        int ra, rb;
        for (int a = 0; a < mod; ++a) {
            for (int b = 0; b < mod; ++b) {
                int x = X[0], f = 1;
                for (int i = 0; i < n; ++i) {
                    if (x != X[i]) {
                        f = 0; break;
                    }
                    x = (x * a + b) % mod;
                    x = (x * a + b) % mod;
                }
                if (f) {
                    ra = a, rb = b;
                    a = mod, b = mod;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            printf("%d\n", (X[i] * ra + rb) % mod);
    }
    return 0;
}
