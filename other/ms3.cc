#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int maxm = 105;
const int maxn = 10005;
int n, m, k;
int O[maxm], os[maxn], om[maxn];
struct stu {
    int sn;
    int p, cp;
    int ct;
    int w[maxm];
    int o[maxm];
} S[maxn];

long long ans[maxn];

bool operator < (const stu & a, const stu & other) {
    return a.sn < other.sn;
}

int main() {
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &S[i].sn, &S[i].ct, &S[i].p);
            for (int j = 0; j < S[i].p; ++j) {
                scanf("%d%d", &S[i].o[j], &S[i].w[j]);
            }
            S[i].cp = 0; S[i].ct += k;
        }
        sort(S, S + n);
        //for (int i = 0; i < n; ++i) printf("%d %d %d\n", S[i].sn, S[i].ct, S[i].p);
        memset(O, 0, sizeof O);
        bool end = false;
        while (true) {
            int st = 0, mx = 0;
            for (int i = 1; i <= m; ++i) om[i] = 1e9;
            for (int i = 0; i < n; ++i) {
                if (S[i].p == S[i].cp) continue;
                int p = S[i].o[S[i].cp];
                if (S[i].ct < om[p] && S[i].ct <= O[p]) om[p] = S[i].ct, os[p] = i;
                //printf("S %d %d %d\n", i, S[i].ct, p);
            }
            end = true;

            for (int i = 1; i <= m; ++i) {
                int si = os[i];
                if (S[si].cp == S[si].p) {
                    continue;
                }
                int cp = S[si].cp;
                //printf("%d %d %d\n",S[si].sn, cp, S[si].ct);
                if (O[i] < S[si].ct) O[i] = S[si].ct;
                O[i] += S[si].w[cp];
                S[si].ct = O[i];
                ++S[si].cp;
                if (S[si].cp != S[si].p) S[si].ct += k;
            }
            for (int i = 0; i < n; ++i) {
                //printf("Check %d %d\n", i, S[i].cp);
                if (S[i].cp != S[i].p) {
                    end = false;
                    break; 
                }
            }
            if (end) break;
        }
        for (int i = 0; i < n; ++i) printf("%d\n", S[i].ct);
    }
    return 0;
}
