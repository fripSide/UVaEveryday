#include <cstdio>

const int maxn = 1000001;
int s[maxn], top = 0;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int l = 0, a = 0;
        top = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (top > 0) {
                l = s[top];
                if ((l + a) % 2 == 0) {
                    s[++top] = a;
                } else --top;
            } else s[++top] = a;
        }
        printf("%d\n", top);
    }
    return 0;
}
