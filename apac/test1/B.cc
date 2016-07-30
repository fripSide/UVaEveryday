#include <cstdio>

const int maxn = 51;
int N, K;
int ans = 0;
int d[4][maxn];

void dfs(int b, int li, int p) {
    if (b == K && li == 4) {
        ans += 1;
       // printf("\n%d\n", b);
        return;
    }
    if (li >= 4) return;
    for (int j = 0; j < N; ++j) {
        int bb = b ^ d[li][j];
        //printf(" b=%d d=%d ", bb, d[li][j]);
        //printf("li=%d b=%d \n", li, b);
        dfs(bb, li + 1, j);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cid = 1; cid <= T; ++cid) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &d[i][j]);
            }
        }
        ans = 0;
        dfs(0, 0, 0);
        printf("Case #%d: %d\n", cid, ans);
    }   
    return 0;
}
