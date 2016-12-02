#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;
int mp[maxn][maxn];
int R, C;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < maxn; i++) {
        int j = 0;
        if (i % 3 == 0) {
            while (j < maxn) { // 110
                mp[i][j] = 1;
                if (j + 1 < maxn) mp[i][j + 1] = 1;
                j += 3;
            }
        } else if (i % 3 == 1) { // 101
            j = 0;
            while (j < maxn) {
                mp[i][j] = 1;
                if (j + 1 < maxn) mp[i][j + 1] = 0;
                if (j + 2 < maxn) mp[i][j + 2] = 1;
                j += 3;
            }
        } else if (i % 3 == 2) { // 011
            j = 0;
            while (j < maxn) {
                mp[i][j] = 0;
                if (j + 1 < maxn) mp[i][j + 1] = 1;
                if (j + 2 < maxn) mp[i][j + 2] = 1;
                j += 3;
            }
        }
    }
    for (int tCase = 1; tCase <= T; tCase++) {
        int ans = 0;
        scanf("%d%d", &R, &C);
        if (R < C) swap(R, C);
        if (R <= 2) ans = R * C;
        else if (C == 2) {
            for (int i = 0; i < R; i++) {
                ans += mp[i][0];
            }
            ans *= 2;
        } else {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) 
                    ans += mp[i][j];
            }
        }
        printf("Case #%d: %d\n", tCase, ans);
    }
}
