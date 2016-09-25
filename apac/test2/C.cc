#include <cstdio>

int main() {
    int T, N, L1, R1, A, B, C1, C2, M, N;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d%d%d%d%d%d", &N, &L1, &R1, &A, &B, &C1, &C2, &M);
        long long x1 = L1, y1 = R1;
        int mi = (y1 - x1 + 1) % M;
        for (int j = 1; j <= N; ++j) {
            x1 = (x1 * A + B * y1 + C1) % M;
            y1 = (x1 * A + B * x1 + C1) % M;
        }
    }
    return 0;
}
