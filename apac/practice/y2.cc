#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>

bool mp[100][100];
int n, k;
int mi[1005];

int dis(int x, int y, int m) {
      int dd = 0;
      int xc = (k + 1) / 2, yc = (k + 1) / 2;
      for (int i = y; i < y + m; ++i) {
        dd += abs(x - xc) + abs(i - yc);
      }
      return dd;
}

void calc(int m) {
     int mx = 10000, myl = 10000, md = 1000000;
     for (int x = 1; x <= k; ++x) {
         for (int y = 1; y <= k - m + 1; ++y) {
            bool can = true;
            for (int i = y; i < y + m; ++i) if (mp[x][i]) can = false;
            if (can) {
                int d = dis(x, y, m);
                if (d < md) {
                    mx = x, myl = y;
                    md = d;
                } else if (d == md) {
                    if (x < mx || (x == mx && y < myl)) {
                        mx = x, myl = y;     
                    }
                }
            }
         }
     }
     if (md == 1000000) printf("-1\n");
     else {
           for (int i = myl; i < myl + m; ++i) mp[mx][i] = true;
           printf("%d %d %d\n", mx, myl, myl + m - 1);
     }
     
}

void solve() {
      memset(mp, false, sizeof mp);
      for (int i = 0; i < n; ++i) {
          calc(mi[i]);
      }
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
         for (int i = 0; i < n; ++i) scanf("%d", mi + i);
         solve();
    }
    return 0;     
}
