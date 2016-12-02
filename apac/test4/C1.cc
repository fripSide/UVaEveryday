#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cstdarg>

using namespace std;

typedef long long ll_t;

void debug(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

const int M = 1000000007;

int T;
int V, S;
unordered_map<string, int> dict;
unordered_map<char, unordered_set<string>> table;
char s[4001];
int N;
ll_t memo[4000];

ll_t solve(int i) {
    if (i >= N) return 1;
    ll_t &ret = memo[i];
    if (ret != -1) return ret;
    ret = 0;
    for (auto& word : table[s[i]]) {
        if (N - i < word.size()) continue;
        string w(s, i, word.size());
        sort(w.begin(), w.end());
        if (w == word) 
            ret += dict[w] * solve(i + w.size());
        ret %= M;
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int icase = 1; icase <= T; icase++) {
        scanf("%d%d", &V, &S);
        dict.clear();
        table.clear();
        for (int i = 0; i < V; i++) {
            char v[21];
            scanf("%s", v);
            sort(v, v + strlen(v));
            dict[v] += 1;
            for (int i = 0; i < strlen(v); i++)
                table[v[i]].insert(v);
        }
        printf("Case #%d:", icase);
        for (int i = 0; i < S; i++) {
            scanf("%s", s);
            N = strlen(s);
            memset(memo, -1, sizeof memo);
            printf(" %lld", solve(0));
        }
        printf("\n");
    }
    return 0;
}
