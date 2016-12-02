#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define NV  1001
#define NR  101

int N, M;
int S[NV] = {0};
vector<int> L[NV];
int dp[NV][3][NR];  // 0: no put, no add; 1: no put, add; 2: put, add

int solve(int root, int parent, int state, int m) {
    int& ret = dp[root][state][m];
    if (ret != -1) return ret;

    int n = L[root].size();
    vector<int> child;
    for (int i = 0; i < n; i++) {
        if (L[root][i] != parent)
            child.push_back(L[root][i]);
    }
    
    ret = 0;
    if (child.size() == 1) {
        if(state == 0) {
            int s = solve(child[0], root, 0, m);
            if (ret < s) ret = s;
            if (m > 0) {
                int t = solve(child[0], root, 2, m-1) + S[root] + S[child[0]];
                if (ret < t) ret = t;
            }
        } else if (state == 1) {
            int s = solve(child[0], root, 0, m);
            if (ret < s) ret = s;
            if (m > 0) {
                int t = solve(child[0], root, 2, m-1) + S[child[0]];
                if (ret < t) ret = t;
            }
        } else {
            int s = solve(child[0], root, 1, m) + S[child[0]];
            if (ret < s) ret = s;
            if (m > 0) {
                int t = solve(child[0], root, 2, m-1) + S[child[0]];
                if (ret < t) ret = t;
            }
        }
    } else if (child.size() == 2) {
        for (int i = 0; i <= m; i++) {
            if (state == 0) {
                int w = solve(child[0], root, 0, i) + solve(child[1], root, 0, m-i);
                if (ret < w) ret = w;
                if (i > 0) {
                    int x = solve(child[0], root, 2, i-1) + solve(child[1], root, 0, m-i) 
                            + S[root] + S[child[0]];
                    if (ret < x) ret = x;
                }
                if (i < m) {
                    int y = solve(child[0], root, 0, i) + solve(child[1], root, 2, m-i-1) 
                            + S[root] + S[child[1]];
                    if (ret < y) ret = y;
                }
                if (i > 0 && i < m) {
                    int z = solve(child[0], root, 2, i-1) + solve(child[1], root, 2, m-i-1) 
                            + S[root] + S[child[0]] + S[child[1]];
                    if (ret < z) ret = z;
                }
            } else if (state == 1) {
                int w = solve(child[0], root, 0, i) + solve(child[1], root, 0, m-i);
                if (ret < w) ret = w;
                if (i > 0) {
                    int x = solve(child[0], root, 2, i-1) + solve(child[1], root, 0, m-i) 
                            + S[child[0]];
                    if (ret < x) ret = x;
                }
                if (i < m) {
                    int y = solve(child[0], root, 0, i) + solve(child[1], root, 2, m-i-1) 
                            + S[child[1]];
                    if (ret < y) ret = y;
                }
                if (i > 0 && i < m) {
                    int z = solve(child[0], root, 2, i-1) + solve(child[1], root, 2, m-i-1) 
                            + S[child[0]] + S[child[1]];
                    if (ret < z) ret = z;
                }
            } else {
                int w = solve(child[0], root, 1, i) + solve(child[1], root, 1, m-i)
                        + S[child[0]] + S[child[1]];
                if (ret < w) ret = w;
                if (i > 0) {
                    int x = solve(child[0], root, 2, i-1) + solve(child[1], root, 1, m-i) 
                            + S[child[0]] + S[child[1]];
                    if (ret < x) ret = x;
                }
                if (i < m) {
                    int y = solve(child[0], root, 1, i) + solve(child[1], root, 2, m-i-1) 
                            + S[child[0]] + S[child[1]];
                    if (ret < y) ret = y;
                }
                if (i > 0 && i < m) {
                    int z = solve(child[0], root, 2, i-1) + solve(child[1], root, 2, m-i-1) 
                            + S[child[0]] + S[child[1]];
                    if (ret < z) ret = z;
                }
            }
        }
    }

    //printf("%d %d %d %d: %d\n", root, parent, state, m, ret);
    return ret;
}


int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &S[i]);
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        L[x].push_back(y);
        L[y].push_back(x);
    }

    memset(dp, -1, sizeof dp);  

    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (L[i].size() < 3) {
            root = i;
            break;
        }
    }

    int res1 = solve(root, 0, 0, M);
    int res2 = solve(root, 0, 2, M - 1) + S[root];
    printf("%d\n", max(res1, res2));
    return 0;
}
