#include <cstdio>
#include <memory.h>
#include <algorithm>

typedef long long LL;
const LL M = 1E9 + 7;
int AK[100001], BK[100001];

LL calc(LL i, LL t, int k) { // i ^ t
    if (t == 0) return 1;
    LL res = 1;
    while (t != 0) {
        if (t % 2 == 1) {
            res *= i;
            res %= k;
        }
        t /= 2;
        i *= i;
        i %= k;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        LL A, B, N, K;
        scanf("%lld%lld%lld%lld", &A, &B, &N, &K);
        memset(AK, 0, sizeof AK);
        memset(BK, 0, sizeof BK);
        int cc = 0;
        int kk = std::min(N, K - 1);
        for (int j = 1; j <= kk; ++j) {
            int ta = calc(j, A, K);
            int tb = calc(j, B, K);
            //printf("%d %d %d--\n", j, ta, tb);
            AK[ta] += (N / K) + ((N % K) >= j);
            BK[tb] += (N / K) + ((N % K) >= j);
            //printf("%d %d==\n", AK[ta], BK[tb]);
            if ((ta + tb) % K == 0 && K != 1) {
                 ++cc;
                //printf("equal %d %d %d %d %d\n", ta, tb, (ta + tb), j, cc);
            }
        }
        LL ans = 0;
        BK[K] = BK[0];
        AK[K] = AK[0];
        ans = (N / K) * (N / K - 1) % M;
        for (int j = 0; j <= K; ++j) {
            ans += (AK[j] * (LL) BK[K - j]) % M;
        }
        //printf("%lld %d..\n", ans, cc);
        ans -= cc;
        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}
