#include <cstdio>
#include <algorithm>

typedef long long LL;

int main() {
    int T;
    LL L, R;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        LL ans = 0;
        scanf("%lld%lld", &L, &R);
        LL mi = std::min(L, R);
        ans = mi * (mi + 1) / 2;
        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}
