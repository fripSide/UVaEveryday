#include <cstdio>

typedef long long LL;
int N, D;

int main() {
    int T;
    scanf("%d", &T);
    for (int iCase = 1; iCase <= T; iCase++) {
        scanf("%d%d", &N, &D);
        int d = D;
        LL cnt = 0;
        for (int i = d; i < N; i += d) {
            int t = N / i;
            int r = N % i;
            int t2 = (N - i) / (i + 2);
            // r 个 1
            if (i <= 2) {
                
            } else {
                    
            }
        }
        printf("Case #%d: %lld\n", iCase, cnt);
    }
    return 0;
}
