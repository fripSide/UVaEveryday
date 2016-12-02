#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100005;
char buf[maxn], nt[3];
int ch[30][30];
bool use[maxn];

int main() {
    int n, m;
    int dp[100];
    while (scanf("%d", &n) != EOF) {
        scanf("%s", buf);
        memset(ch, 0, sizeof ch);
        memset(dp, 0, sizeof dp);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%s", nt);
            ch[nt[0] - 'a'][nt[1] - 'a'] = ch[nt[1] - 'a'][nt[0] - 'a'] = 1;
        }
        dp[buf[0] - 'a'] = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int cur = buf[i] - 'a';
            int v = dp[cur];
            for (int j = 0; j < 26; ++j) {
                if (ch[cur][j] == 0)
                    v = max(v, dp[j] + 1);
            }
            dp[cur] = v;
            ans = max(ans, v);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
