#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1005;
const int maxm = 105;
int S[maxn], edge_cnt[maxn];
int dp[maxn][3][maxm];
int n, m;
vector<int> G[maxn];
int tmp[maxm];

void init(int nPoint) {
    G[nPoint].clear();
    edge_cnt[nPoint] = 0;
    memset(dp[nPoint], 0, sizeof dp[nPoint]);
}

void dfs(int y, int father) {
    vector<int> son_pool;
    son_pool.clear();
    for (int i = 0; i < (int)G[my].size(); ++i) {
        int son = G[my][i];
        if (son != father) {
            dfs(son, my);
            son_pool.push_back(son);
        }
    }

    int son, x, y;
    switch ((int) son_poll.size()) {
        case 0:
            dp[my][0][1] = S[my];
            break;
        case 1:
            son = son_pool[0];
            for (int i = 1; i <= m; ++i) {
                int max_in_son = dp[son][0][i - 1];
                max_in_son = max(max_in_son, dp[son][1][i - 1] + S[son]);
                max_in_son = max(max_in_son, dp[son][2][i - 1]);
                dp[my][0][i] = max_in_son + S[my];

            }

    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            init(i);
            scanf("%d", &S[i]);
        }
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
            edge_cnt[x]++;
            edge_cnt[y]++;
        }
        int root = 1;
        for (int i = 1; i <= n; ++i) {
            if (edge_cnt[i] < 3) {
                root = i;
                break;
            }
        }
        dfs(root, root);
        int ans = 0;
        for (int j = 0; j < 3; ++j)
            //for (int i = 0; i <= m; ++i)
            ans = max(ans, dp[root][j][m]);
        printf("%d\n", ans);
    }
    return 0;
}
