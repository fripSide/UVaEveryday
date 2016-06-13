#include <cstdio>
#include <cstring>

const int maxn = 105;
bool g[maxn];

void judge(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    memset(g, false, sizeof g);
    int wnum = 0;
    for (int i = 0; i < len2; ++i) {
        bool in = false;
        for (int j = 0; j < len1; ++j) {
            if (s1[j] == s2[i]) {
                if (!g[j]) {
                    g[j] = true;
                    in = true;  
                }
            }
        }
        if (!in) wnum += 1;
        if (wnum >= 7) break;
    }
    bool win = true;
    for (int i = 0; i < len1; ++i) {
        if (!g[i]) win = false;
    }
    if (win) puts("You win.");
    else if (wnum < 7) puts("You chickened out.");
    else puts("You lose.");
}

int main() {
    int t;
    char org[maxn], gus[maxn];
    while (scanf("%d", &t) != EOF && t != -1) {
        scanf("%s%s", org, gus);
        printf("Round %d\n", t);
        judge(org, gus);    
    }
    return 0;
}
