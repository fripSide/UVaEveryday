#include <cstdio>
#include <cstring>

bool less(const char *str, int p, int q, int l) {
    for (int i = 0; i < l; ++i) {
        if (str[(p + i) % l] != str[(q + i) % l])
            return str[(p + i) % l] < str[(q + i) % l];
    }
    return false;
}

int main() {
    int n;
    const int maxn = 101;
    char s[maxn];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int ans = 0;
        int l = strlen(s);
        for (int i = 1; i < l; i++) {
            if (less(s, i, ans, l)) ans = i;
        }
        for (int i = 0; i < l; i++) 
            putchar(s[(i + ans) % l]);
        putchar('\n');
    } 
    return 0;
}   
