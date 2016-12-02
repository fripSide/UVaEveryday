#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n, m;
int x[maxn], y[maxn];
long long ans;
int px, py, tmpx, tmpy;

void Dox(){
    ans += (long long) (m + 1 - tmpy) * (long long) x[px];
    px++;
    tmpx++;
}

void Doy(){
    ans += (long long ) (n + 1 - tmpx) * (long long)y[py];
    py++;
    tmpy++;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d", &x[i]);
    for(int i = 1; i <= m; i++)scanf("%d", &y[i]);
    sort(x + 1, x + n + 1);
    sort(y + 1, y + m + 1);
    tmpx = 0, tmpy = 0;
    ans = 0;
    int cnt = n + m;
    px = 1, py = 1;
    while(cnt--){
        if(px > n) {
            Doy();
        } else if(py > m) {
            Dox();
        } else if(x[px] <= y[py]){
            Dox();
        } else {
            Doy();
        }
    }
    printf("%lld\n", ans);
    return 0;
}
