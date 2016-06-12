#include <cstdio>
#include <memory.h>

int main() {
    int a, b;
    int maxn = 100000;
    int yu[maxn], sh[maxn];
    while (scanf("%d %d", &a, &b) != EOF) {
        int v = 1;        
        memset(yu, 0, sizeof yu);
        memset(sh, 0, sizeof sh);
        int d = a / b, rb = 0, re = 0;
        for (int i = 0; i < maxn; ++i) {
            if (i == 0) yu[0] = a % b;
            else yu[i] = yu[i - 1] * 10 % b;
            sh[i] = yu[i] * 10 / b;
            for (int j = 0; j < i; ++j) {
                if (yu[i] == yu[j]) {
                    rb = j, re = i;
                    i = maxn;
                    break;
                }
            }
        }
        printf("%d/%d = %d.", a, b, d);
        for (int i = 0; i < re; ++i) {
            if (i ==  rb) printf("(");
            if (i < 50) printf("%d", sh[i]);
            if (i == re - 1 && i <= 50) printf(")");
            else if (i > 50) {
                printf("...)");
                break;
            }
        }
        printf("\n   %d = number of digits in repeating cycle\n\n", re - rb);
    }
    return 0;
}
