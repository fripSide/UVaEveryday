#include <cstdio>



int main() {
    int n;    
    int A[20];
    int c = 1;
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", A + i);
        long long res = 1, mx = 0;
        for (int i = 0; i < n; ++i) {
            res = 1;
            for (int j = i; j < n; ++j) {
                res *= A[j];
                if (res > mx) mx = res;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", c++, mx);
    }
    return 0;
}
