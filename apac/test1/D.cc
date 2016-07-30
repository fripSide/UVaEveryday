#include <cstdio>
#include <algorithm>

const int maxs = 1000005;
int N, T, Q;
int a[maxs];
long long sum[maxs];
long long all[maxs];

int main() {
    int T;
    scanf("%d", &T);
    for (int cid = 1; cid <= T; ++cid) {
        scanf("%d%d", &N, &Q);  
        for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
        //std::sort(a, a + N);
        int s = 1, p = 1;
        while (s <= N) {
            sum[p] = 0;
            for (int i = 0; i <= N - s; ++i) {
                for (int j = 0; j < s; ++j) sum[p] += a[i + j];
                ++p;
            }
            ++s;
        }
        int ma = N * (N + 1) / 2;
        std::sort(sum + 1, sum + ma + 1);
        //for (int i = 1; i <= ma; ++i) printf("%d ", sum[i]);
        all[0] = 0;
        for (int i = 1; i <= ma; ++i) {
            all[i] = all[i - 1] + sum[i];
           // printf(" %d", all[i]);
        }
        printf("Case #%d:\n", cid);
        int l, r;
        for (int i = 0; i < Q; ++i) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", all[r] - all[l - 1]);
        }
    }
    return 0;
}
