#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;

int main() {
    char mp[5][7];
    const int maxn = 1005;
    char s[maxn];
    int idx = 1;
    while (true) {
        bool end = false;
        for (int i = 0; i < 5; i++) {
            fgets(mp[i], 7, stdin);
            if (mp[0][0] == 'Z') {
                 end = true;
                 break;
            }
        }
        if (end) break;
        int x, y;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (mp[i][j] == ' ') {
                    x = i, y = j;
                    i = j = 5;
                }
            }
        }
        
        //memset(s, 0, sizeof s);
        int p = 0;
        while (p < maxn) {
            char tmp = getchar();
            if (tmp == '0') break;
            s[p++] = tmp;
        }
        s[p] = 0;
        getchar();
        bool has = true;    
        for (int i = 0; i < s[i]; ++i) {
            int tx = x, ty = y;
            if (s[i] == 'A') {
                tx = x - 1;
            } else if (s[i] == 'L') {
                ty = y - 1;
            } else if (s[i] == 'R') {
                ty = y + 1;
            }
            // 这里不能用else，输入可能有其他的字符,例如： \t \n \space等
            else if (s[i] == 'B'){
                tx = x + 1;
            }
            if (tx < 0 || ty < 0 || tx > 4 || ty > 4) {
                has = false; break;
            }
            mp[x][y] = mp[tx][ty];
            mp[tx][ty] = ' ';
            x = tx, y = ty;
        }
        if (idx > 1) printf("\n");
        printf("Puzzle #%d:\n", idx++);
        if (!has) {
            printf("This puzzle has no final configuration.\n");
            continue;
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (j) printf(" ");
                printf("%c", mp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
