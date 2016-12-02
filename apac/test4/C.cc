#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
#include <set>

using namespace std;

const int maxn = 105;
const int MOD = 1e9 + 7;
int V, S;
string words[maxn];
char eb[55];
long long dp[maxn];

int main() {
    int T;
    scanf("%d", &T);
    for (int tCase = 1; tCase <= T; tCase++) {
        int ans = 0;
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &V, &S);
        for (int i = 0; i < V; ++i) {
             char buf[20];
             scanf("%s", buf);
             words[i] = buf;
             sort(words[i].begin(), words[i].end());    
            // dp[words[i].size()] = 1;
            // printf("%s\n", words[i].data());
        }
        dp[0] = 1;
        printf("Case #%d:", tCase);
        for (int t = 0; t < S; ++t) {
            scanf("%s", eb);
            // printf("%s\n", eb);
            int len = strlen(eb);
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < V; ++j) {
                    int sz = words[j].size();      
                    if (i >= sz - 1) {
                        string wd(eb, i - sz + 1, sz);
                        sort(wd.begin(), wd.end());
                        if (wd == words[j]) {
                            dp[i] += dp[i - sz + 1];
                            dp[i] %= MOD;
                            printf("%d %d contains %s\n", i, i - sz + 1, wd.data());
                        }
                    }
                }
            }
            printf(" %lld", dp[len - 1]);
        }
        printf("\n");
    }
}
