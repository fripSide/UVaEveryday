#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long LL;
const int maxn = 100005;
const LL MOD = 1e9 + 7;
int ti[maxn], ai[maxn];
int N;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &ti[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &ai[i]);
    int mxt = 0, mxa = 0;
    LL num = 1;
    for (int i = 1; i <= N; i++) {
        if (i > 1 && i < N) {
            if (ti[i] == ti[i - 1] && ai[i] == ai[i + 1]) {
                num *= min(ai[i], ti[i]);
                num %= MOD;
            } else if (ti[i] < ti[i - 1] || ai[i] < ai[i + 1]){
                num = 0;
            }
        }
        mxt = max(mxt, ti[i]);
        mxa = max(mxa, ai[i]);
    }
    if (mxt == mxa) {
        printf("%lld\n", num);
    } else puts("0");
    return 0;
}
