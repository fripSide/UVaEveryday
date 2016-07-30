#include <cstdio>
#include <memory.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    const int maxn = 15;
    char mp[maxn][maxn];
    int num[maxn][maxn];
    int r, c, idx = 1;
    map<int, string> out;
    while (scanf("%d %d", &r, &c) != EOF && r != 0) {
        for (int i = 0; i < r; i++) {
            scanf("%s", mp[i]);
        }
        memset(num, 0, sizeof num);
        if (idx > 1) printf("\n");
        printf("puzzle #%d:\nAcross\n", idx++);
        int n = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int t = i - 1, l = j - 1;
                if (mp[i][j] == '*') continue;
                if (t == -1 || l == -1) {
                    num[i][j] = ++n;
                } else if (mp[t][j] == '*' || mp[i][l] == '*') {
                    num[i][j] = ++n;
                } 
            }
        }

        out.clear();
        // across
        for (int i = 0; i < r; ++i) {
            int t = -1;
            for (int j = 0; j < c; ++j) {
                if (mp[i][j] != '*') {
                    if (t == -1) out[t = num[i][j]] = "";
                    out[t] += mp[i][j];
                } else {
                    t = -1;
                }
            }
        }
        map<int, string>::iterator it = out.begin();
        while (it != out.end()) {
            if (it->first < 10)
                printf("  %d.%s\n", it->first, it->second.data());
            else 
                printf(" %d.%s\n", it->first, it->second.data());
            ++it;
        }
        out.clear();
        // down
        printf("Down\n");
        for (int j = 0; j < c; ++j) {
            int t = -1;
            for (int i = 0; i < r; ++i) {
                if (mp[i][j] != '*') {
                    if (t == -1) out[t = num[i][j]] = "";
                    out[t] += mp[i][j];
                } else {
                    t = -1;
                }
            }
        }
        it = out.begin();
        while (it != out.end()) {
            if (it->first < 10)
                printf("  %d.%s\n", it->first, it->second.data());
             else
                 printf(" %d.%s\n", it->first, it->second.data());
             ++it;
         }
    }
    return 0;
}
