#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;

int M, N, P;
int cube[10][10][10];
int sc[15][10][10][10];
int sl[15];
bool su[15];
bool vis[10][10][10];

int go[3][3] = {0,0,1, 0,1,0, 1,0,0};

void calc(int x, int y, int z, int s, bool add) {
    int v = add ? 1 : -1;
    for (int i1 = 0; i1 < sl[s]; ++i1)
    for (int i2 = 0; i2 < sl[s]; ++i2)
    for (int i3 = 0; i3 < sl[s]; ++i3)
        cube[x + i1][y + i2][z + i3] += v * sc[s][i1][i2][i3]; 
}

bool check() {
    for (int i1 = 0; i1 < M; ++i1)
    for (int i2 = 0; i2 < M; ++i2)
    for (int i3 = 0; i3 < M; ++i3)
        if (cube[i1][i2][i3] % P != 0) return false;
    return true;
}

bool dfs(vector<int> &ans) {
    if (check()) {
        for (int i = 0; i < ans.size(); i += 3) {
            printf("%d %d %d\n", ans[i], ans[i + 1], ans[i + 2]);
        }
        return true;
    }
    for (int i1 = 0; i1 < M; ++i1)
    for (int i2 = 0; i2 < M; ++i2)
    for (int i3 = 0; i3 < M; ++i3)
    for (int i = 0; i < N; ++i) {
        
        if (su[i]) continue;
        if (i1 + sl[i] >= M || i2 + sl[i] >= M || i2 + sl[i] >= M) continue;
        calc(i1, i2, i3, i, true);
        su[i] = true;
        ans.push_back(i1);ans.push_back(i2);ans.push_back(i3);
        if (dfs(ans)) return true;
        su[i] = false;
        calc(i1, i2, i3, i, false);
        ans.pop_back(); ans.pop_back(); ans.pop_back();
    }
    return false;
}

int main() {
    scanf("%d%d%d", &M, &N, &P);
    memset(cube, 0, sizeof cube);
    memset(sc, 0, sizeof sc);
    memset(sl, 0, sizeof sl);
    memset(su, false, sizeof su);
    memset(vis, false, sizeof vis);
    for (int i = 0; i < M; ++i) 
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < M; ++k)
                scanf("%d", &cube[i][j][k]);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &sl[i]);
        for (int j = 0; j < sl[i]; ++j)
            for (int k = 0; k < sl[i]; ++k)
                for (int l = 0; l < sl[i]; ++l)
                    scanf("%d", &sc[i][j][k][l]);
    }
    vector<int> res;
    dfs(res);
    return 0;
}
