#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 405;
int K, mh = 0;
struct block {
    int a, b, c;
    bool operator < (const block & other) const {
        return b < other.b;
    }
} b[maxn];

int solve() {
    int dp[40005] = {0};
    dp[0] = 1;
    for (int i = 0; i < K; i++) {
        for (int j = b[i].b; j >= 0; j--) {
            for (int k = 1; k <= b[i].c; k++) {
                if (j - k * b[i].a >= 0 && dp[j - k * b[i].a] == 1) dp[j] = 1;
            }
        }
    }
    for (int i = mh; i >= 0; i--) if (dp[i]) return i;
    return 0;
}

int main() {
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d%d", &b[i].a, &b[i].b, &b[i].c);
        if (b[i].b > mh) mh = b[i].b;
    }
    sort(b, b + K);
    printf("%d\n", solve());
    return 0;
}
