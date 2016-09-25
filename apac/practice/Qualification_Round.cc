#include <cstdio>
#include <algorithm>
#include <functional>

// https://code.google.com/codejam/contest/438101/dashboard#s=p2

const int maxn = 65;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int p, c;
        scanf("%d %d", &p, &c);
        long long s[maxn];
        for (int j = 0; j < p; ++j) 
            scanf("%lld", s + j);
        long long sum = 1E17, last = sum + 1;
        while (last > sum) {
            last = sum;
            sum = 0;
            for (int j = 0; j < p; ++j)
                sum += s[j];
            sum /= c;
            for (int j = 0; j < p; ++j) {
                if (s[j] > sum) s[j] = sum;
            }
        }
        printf("Case #%d: %lld\n", i, sum);
    }
    return 0;
}
