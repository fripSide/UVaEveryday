#include <cstdio>

const int maxn = 100005;
int n, A[maxn];
long long ans;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
    ans = 0;
    int p = 1;
    for(int i = 1; i <= n; ++i) {
        int v = A[i] / p;
        if(A[i] % p == 0) v--;
        if(A[i] >= p) {
            ans += v;
            if(A[i] == p || i == 1) p++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
