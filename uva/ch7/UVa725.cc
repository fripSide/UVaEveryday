#include <cstdio>
#include <memory.h>

bool mk[10];
bool has;
int n;
bool check(int res) {
    if (res > 100000) return false;
    bool fill[10] = {false};
    while (res > 0) {
        fill[res % 10] = true;
        res /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        if (fill[i] || mk[i]) continue;
        return false;
    }
    return true;
}

void dfs(int v, int c) {
    if (c == 5) {
        int s = n * v;
        if (check(s)) {
            printf("%d / %05d = %d\n", s, v, n);
            has = true;
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (mk[i]) continue;
        mk[i] = true;
        dfs(v * 10 + i, c + 1);
        mk[i] = false;
    }
}

int main() {
    bool first = true;
    while (scanf("%d", &n) != EOF && n != 0 ) {
        if (!first) puts("");
        first = false;
        memset(mk, false, sizeof mk);
        has = false;
        dfs(0, 0);
        if (!has) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
