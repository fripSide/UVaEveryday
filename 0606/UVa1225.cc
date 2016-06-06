#include <cstdio>
#include <memory.h>

int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        int ans[10];
        while (scanf("%d", &n) != EOF) {
            memset(ans, 0, sizeof ans);
            for (int i = 1; i <= n; i++) {
                int t = 0, v = i;
                while (v != 0) {
                    t = v % 10;
                    v /= 10;
                    ans[t]++;
                }
            }
            for (int i = 0; i < 9; i++) 
                printf("%d ", ans[i]);
            printf("%d\n", ans[9]);
        }  
    }
    return 0;
}
