#include <cstdio>
#include <memory.h>
#include <algorithm>

int mp[11][10], r[2][2], h[2][2], c[2][2], g[2][2];
int bx, by;
int n, pr, ph, pc, pg;

bool check(int x, int y) {
    //printf("%d %d ", x, y);
    if (x < 1 || x > 3 || y < 4 || y > 6) return false;
    for (int i = 0; i < pr; ++i) {
        int tx = r[i][0], ty = r[i][1];
        if (tx == x && ty == y) continue;
        bool block = false;
        if (tx == x) {
            int mi = std::min(ty, y);
            int mx = std::max(ty, y);
            for (int j = mi + 1; j < mx; ++j) {
                if(mp[tx][j] == 1) block = true;
            }
            if (!block) return false;
        } else if (ty == y) {
            int mi = std::min(tx, x);
            int mx = std::max(tx, x);
            for (int j = mi + 1; j < mx; ++j) {
                if(mp[j][ty] == 1) block = true;
            }
            if (!block) return false;
        }
    }
    for (int i = 0; i < ph; ++i) {
        int tx = h[i][0], ty = h[i][1];
        if (tx == x && ty == y) continue;
        int m1[] = {-2, 2}, m2[] = {-1, 1};
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int nx = tx + m1[j], ny = ty + m2[k]; 
                if (nx > 0 && nx <= 10 && ny > 0 && ny < 10) {
                    if (mp[tx + m1[j]/ 2][ty] != 1 && nx == x && ny == y) return false;
                }
                nx = tx + m2[k], ny = ty + m1[j];
                if (nx > 0 && nx <= 10 && ny > 0 && ny < 10) {
                    if (mp[tx][ty + m1[j] / 2] != 1 && nx == x && ny == y) return false;
                }
            }
        }
    }
    for (int i = 0; i < pc; ++i) {
        int tx = c[i][0], ty = c[i][1];
        if (tx == x && ty == y) continue;
        if (ty == y) {
            int mi = std::min(tx, x);
            int mx = std::max(tx, x);
            int bn = 0;
            for (int j = mi; j < mx; ++j) {
                if (mp[j][ty] == 1) bn++;
            }
            if (bn == 1) return false;
        } else {
            int tx = c[i][0], ty = c[i][1];
            if (tx == x) {
                int mi = std::min(ty, y);
                int mx = std::max(ty, y);
                int bn = 0;
                for (int j = mi + 1; j < mx; ++j) {
                   if (mp[tx][j] == 1) bn++;
                }
                if (bn == 1) return false;
            }
        }
    }
    if (g[0][1] == y) {
        bool block = false;
        for (int i = x + 1; i < g[0][0]; ++i) if (mp[i][y] == 1) block = true;
        if (!block) return false;
    }
    return true;
}

bool check() {
    int t[] = {-1, 1};
    bool ret = false;
    for (int i = 0; i < 2; ++i) {
        ret |= check(bx + t[i], by); 
        ret |= check(bx, by + t[i]);
        //printf("%d\n", ret);
    }
    return ret;
}

int main() {
    while (scanf("%d%d%d", &n, &bx, &by) != EOF) {
        if (n == 0 && bx == 0 && by == 0) break;
        pr = ph = pc = pg = 0;
        memset(mp, 0, sizeof mp);
        memset(r, 0, sizeof r);
        memset(h, 0, sizeof h);
        memset(c, 0, sizeof c);
        memset(g, 0, sizeof g);
        mp[bx][by] = 1;
        for (int i = 0; i < n; ++i) {
            char a[5];
            int x, y;
            scanf("%s %d %d", a, &x, &y);
            if (a[0] == 'R') {
                r[pr][0] = x, r[pr][1] = y, ++pr;
            } else if (a[0] == 'H') {
                h[ph][0] = x, h[ph][1] = y, ++ph;
            } else if (a[0] == 'C') {
                c[pc][0] = x, c[pc][1] = y, ++pc;
            } else if (a[0] == 'G') {
                g[pg][0] = x, g[pg][1] = y;
            }
            mp[x][y] = 1;
        }
        puts(!check() ? "YES" : "NO");   
    }
    return 0;
}
