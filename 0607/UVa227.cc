#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char mp[5][5];
    const int maxn = 200;
    char s[maxn];
    bool cp = true;
    int idx = 1;
    while (true) {
        for (int i = 0; i < 5; i++) fgets( mp[i], 5, stdin);
        if (mp[0][0] == 'Z' && mp[0][1] == 0) break;
        int x, y;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (mp[i][j] == ' ')
                    x = i, y = j;
            }
        }
        for (int i = 0; i < 5; ++i) printf("%s\n", mp[i]);
        printf("\n");
        bool has = true, end = false;
        while (scanf("%s", s) != EOF) {
            for (int i = 0; s[i]; ++i) {
                if (s[i] == '0') {
                    end = true;
                    break;
                }
                if (s[i] == 'A') {
                    if (x - 1 > 0) swap(mp[x][y], mp[x - 1][y]);
                    else has = false;                   
                } else if (s[i] == 'L') {
                    if (y - 1 > 0) swap(mp[x][y], mp[x][y - 1]);
                    else has = false;
                } else if (s[i] == 'R') {
                    if (y + 1 < 5) swap(mp[x][y], mp[x][y + 1]);
                    else has = false;
                } else {
                    if (x + 1 < 5) swap(mp[x][y], mp[x + 1][y]);
                    else has = false;
                }
            }
            if (end) break;
            if (!has) break;
        }
        if (idx > 1) printf("\n");
        printf("Puzzle #%d:\n", idx++);
        if (has) printf("This puzzle has no final configuration.\n");
        else {
            for (int i = 0; i < 5; ++i) {
                printf("%s\n", mp[i]);
            }
        }
    }
    return 0;
}
