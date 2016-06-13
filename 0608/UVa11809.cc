#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    const int maxn = 1000;
    char f[maxn];
    double M[11][31];
    const double min_dif = 1e-5;
    long long E[11][31];
    double m, t;
    long long e;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j <= 30; ++j) {
            e = (1 << j) - 1;
            m = 1 - 1.0 / (1 << (i + 1));
            t = log10(m) + e * log10(2);
            E[i][j] = t / 1;
            M[i][j] = pow(10, t - E[i][j]);
        }
    }
    while (scanf("%s", f) != EOF) {
        if (strcmp(f, "0e0") == 0) break;
        long long B = 0;
        double A;
        f[17] = ' ';
        sscanf(f, "%lf %lld", &A, &B);
        for (int i = 0; i <= 9; ++i) {
            for (int j = 1; j <= 30; ++j) {
                if (B == E[i][j] && fabs(A - M[i][j]) < min_dif) {
                    printf("%d %d\n", i, j);
                    i = 10, j = 31;
                }
            }
        }
    }
    return 0;
}
