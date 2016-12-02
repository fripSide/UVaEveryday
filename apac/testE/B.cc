#include <cstdio>
#include <cmath>

typedef long long LL;
LL N;

bool check(LL b) {
    LL pw = log(N) / log(b) + 1;
    LL res = (pow(b, pw) - 1) / (b - 1);
    //printf("pw=%lld b=%lld  %lld\n", pw, b, N);
    return res == N;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tCase = 1; tCase <= T; tCase++) {
        scanf("%lld", &N);
        LL lo = 2, hi = N - 1, res = N - 1, prd = 2;
        /*
        while (lo < hi) {
            LL mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid - 1;
                res = mid;
            } else lo = mid + 1;
        }
        */
        int t = log(N) / log(2) + 3;
        for (int i = t; i >= 1; i--) {
            lo = 2, hi = N - 1;
            while (lo <= hi) {
                LL mid = (lo + hi) / 2;
                LL rr = pow(mid, i);
                printf("%lld i=%d %lld <----\n",mid, i, rr);
                prd = (rr - 1) / (mid - 1);
                
                if (prd < N) lo = mid + 1;
                else if (prd > N) hi = mid - 1;
                else {
                    if (mid < res) res = mid;
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n", tCase, res);
    }
    return 0;
}
