#include <cstdio>

const int maxn = 100005;
char buf[maxn];
int k;

void solve(int t) {
    char * s = buf, *l = NULL;
    while (*s) {
        if (*s > 'a') {
            int v = 'z' - *s + 1;
            if (v <= t) {
                t -= v;
                *s = 'a';
            } 
        }
        l = s + 1;
        if (*l == 0 && t > 0) {
            *s = (*s - 'a' +  t) % 26 + 'a';
            t = 0;
        }
        printf("%c", *s);
        ++s;
    }
    printf("\n");
}

int main() {
    scanf("%s", buf);
    scanf("%d", &k);
    solve(k);
    return 0;
}
