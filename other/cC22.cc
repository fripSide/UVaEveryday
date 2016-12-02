#include <cstdio>
#include <algorithm>

int K, T;

int main() {
    scanf("%d%d", &K, &T);
    int mx = 0;
    for (int i = 0; i < T; i++) {
        int ai;
        scanf("%d", &ai);
        //printf("%d %d %d\n", K, ai, mx);
        mx = std::max(mx, ai - 1 - (K - ai));
    }
    printf("%d\n", mx);
    return 0;
}
