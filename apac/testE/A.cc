#include <cstdio>
#include <cstring>

const int maxn = 105;
char buf[maxn];
typedef long long LL;
LL len = 0, all = 0;

LL calc(LL s) {
    int l = s % len;
    int cnt = 0;
    for (int i = 0; i < l; i++)
        if (buf[i] == 'B') ++cnt;
    LL ret = (s / len) * all + cnt;
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tCase = 1; tCase <= T; tCase++) {
        scanf("%s", buf);
        len = strlen(buf);
        all = 0;
        for (int i = 0; i < len; i++) {
            if (buf[i] == 'B') ++all;
        }
        LL I, J;
        scanf("%lld %lld", &I, &J);
        
        printf("Case #%d: %lld\n", tCase, calc(J) - calc(I - 1));
    }
    return 0;
}
