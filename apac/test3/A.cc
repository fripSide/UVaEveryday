#include <cstdio>
#include <climits>

int main() {
    float t = 0.6121;
    printf("%.8f\n", t * (1 - t));
    int x = 2147395600, i;
    for (i = 1; i * i <= x; ++i);
    printf("%d, %d, %d, %d\n", x, (i - 1) * (i - 1), i - 1, 46340 * 43340); 
    printf("%d\n", INT_MAX);
    return 0;
}
