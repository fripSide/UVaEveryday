#include <cstdio>

int N, X, K, A, B, C;
double ans = 0.0000000000;

void calc(int t, int d, double r) {
    if (d == N) {
        ans += t * r;
        //printf("d=%d X=%d ans=%.10f rate=%.10f\n", d, t, ans, r);
        return;
    }
    int v1 = t & K, v2 = t | K, v3 = t ^ K;
    if (v1 == v2) {
        calc(v1, d + 1, r * (A + B) / 100.0);
        calc(v3, d + 1, r * C / 100.0); 
    } else if (v2 == v3) {
        calc(v1, d + 1, r * A / 100.0);
        calc(v3, d + 1, r * (B + C) / 100.0);
    } else {
        calc(v1, d + 1, r * (A / 100.0));
        calc(v2, d + 1, r * (B / 100.0));
        calc(v3, d + 1, r * (C / 100.0));
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cid = 1; cid <= T; ++cid) {
        scanf("%d%d%d%d%d%d", &N, &X, &K, &A, &B, &C);
        //printf("%d %d %d %d,%d,%d\n", N, X, K, A, B, C);
        ans = 0.0;
        calc(X, 0, 1.0);
        printf("Case #%d: %.10f\n", cid, ans);
    }
    return 0;
}
