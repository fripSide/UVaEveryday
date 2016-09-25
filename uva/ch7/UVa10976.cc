#include <cstdio>
int ans = 0;
void solve(int k, bool out) {
    int x, y;
    ans = 0;
    for (y = k + 1; ; ++y) {
        for (x = y; ; ++x) {
            if (k * (x + y) == x * y) {
                ++ans;
                if (out) printf("1/%d = 1/%d + 1/%d\n", k, x, y);
            } else if (k * (x + y) < x * y) {
                break;
            }
        }
        if (k * (y + y) < y * y) return;
    }                   
}

int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        solve(k, false);
        printf("%d\n", ans);
        solve(k, true);
    }    
    return 0;
}
