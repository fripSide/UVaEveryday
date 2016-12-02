#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

typedef long long LL;
using namespace std;
const int MOD  = 1e9 + 7;
const int maxn = 405;
LL dp[4005];
vector<string> words;

int main() {
    int T;
    scanf("%d", &T);    
    for (int tCase = 1; tCase <= T; ++tCase) {
        int ans = 0, V, S;
        words.clear();
        scanf("%d%d", &V, &S);
        for (int i = 0; i < V; i++) {
            char buf[20];
            scanf("%s", buf);
            sort(buf, buf + strlen(buf));
            words.push_back(string(buf));
        }
        printf("Case #%d: ", tCase);
        for (int t = 0; t < S; t++) {
            char encip[4005];
            memset(dp, 0, sizeof dp);
            scanf("%s", encip);
            int len = strlen(encip);
            dp[0] = 1;
            // printf("sz=%d\n", words.size());
            for (int i = 1; i <= len; i++) {
                for (int j = 0; j < V; j++) {
                    int sz = words[j].size();
                    if (i >= sz) {
                        string wd(encip, i - sz, sz);
                        //printf("%s %s\n", words[j].data(), wd.data());
                        sort(wd.begin(), wd.end());
                        if (wd == words[j]) {
                            dp[i] += dp[i - sz];
                            dp[i] %= MOD;
                            //printf("eq %d %lld\n", i - sz, dp[i-sz]);
                        }
                    }
                }
            }
            printf("%lld%c", dp[len] % MOD, " \n"[t == S - 1]);
        }
    }
    return 0;
}
