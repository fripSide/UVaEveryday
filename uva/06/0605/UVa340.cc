#include <cstdio>

int main() {
    int n, idx = 1;
    const int max = 1001;
    int t[max], g[max];
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < n; ++i) scanf("%d", t + i);
        printf("Game %d:\n", idx++);
        while (true) {
            int A = 0, B = 0;
            bool b = true;
            for (int i = 0; i < n; ++i){
                scanf("%d", g + i);
                if (g[i] != 0) b = false;
                if (g[i] == t[i]) ++A;
            }
            if (b) break;
            for (int i = 1; i <= 9; ++i) {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; ++j) {
                    if (t[j] == i) ++c1;
                    if (g[j] == i) ++c2;
                }
                if (c1 < c2) B += c1;
                else B += c2;
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}
