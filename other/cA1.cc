#include <cstdio>

const int maxn = 20;

int main() {
    char buf[maxn];
    scanf("%s", buf);
    for (int i = 0; i < 12; ++i) {
        if (i == 4) printf(" %c", buf[i]);
        else printf("%c", buf[i]);
    }
    printf("\n");
    return 0;
}
