#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

int N, K;
int a[10];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
    int mi = 1e9, ret = 0;
    std::sort(a, a + N);
    do {
        for (int i = 0; i < (1 << N); i++) {
            ret = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    ret += a[j];
                } else {
                    ret *= a[j];
                }
            }
            mi = std::min(mi, abs(K - ret));
        }
        for (int i = 0; i < N; ++i) {
            printf("%d%c", a[i], " \n"[i == N - 1]);
        }
    } while (std::next_permutation(a, a + N));
    printf("%d\n", mi);
    return 0;
}
