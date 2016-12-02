#include <cstdio>


int main() {
    char buf[20];
    char cf[] = "CODEFESTIVAL2016";
    int ans = 0;
    scanf("%s", buf);
    for (int i = 0; i < 16; ++i) {
        if (buf[i] != cf[i]) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
