#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int calc(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int cnt = max(len1, len2) - min(len1, len2);
    for (int i = 0; i < min(len1, len2); ++i) {
        if (s1[i] != s2[i]) cnt++;
    }
    return cnt;
}

int main() {
    int t;
    scanf("%d", &t);
    char s[55][1005];
    map<char, int> res;
    while (t--) {
        int m, n;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; ++i) scanf("%s", s[i]);
        string len(1005, 0);
        int num = 0;
        for (int i = 0; i < n; ++i) {
            res.clear();
            for (int j = 0; j < m; ++j) {
                res[s[j][i]] += 1;
            }
            map<char, int>::iterator it = res.begin();
            int mx = 0;
            while (it != res.end()) {
                if (it->second > mx) {
                    len[i] = it->first;
                    mx = it->second;
                }
                ++it;
            }
            num += m - mx;
        }
        printf("%s\n%d\n", len.data(), num);
    }
    return 0;
}
