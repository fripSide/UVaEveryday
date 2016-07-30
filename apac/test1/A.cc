#include <cstdio>
#include <cstring>

const int MAX_N = 1005;
const long long M = 1000000007;
char s[MAX_N];
int idx = 0;

void solve() {
    int len = strlen(s);
    long long ans = 1;
    for (int i = 0; i < len; ++i) {
        int t = 3;
        char a, b, c;
        b = s[i];
        if (i == 0) a = s[i];
        else a = s[i - 1];
        if (i == len - 1) c = s[i];
        else c = s[i + 1];
        if (a == b) {
            if (a == c) t = 1; else t = 2;
        } else if (a == c || b == c) t = 2;
        ans = ans * t % M;
    }
    printf("Case #%d: %d\n", ++idx, (int) ans);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        solve();
    }
    return 0;
}
