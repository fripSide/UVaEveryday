
// http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/

#include <climits>
#include <cstdio>

const int INF = INT_MAX;
const int maxn = 100;
int lc[maxn][maxn];


void solveWordWrap(int l[], int n, int m) {
    int extras[maxn][maxn];
    int c[maxn], p[maxn];
    for (int i = 1; i <= n; ++i) {
        extras[i][i] = m - l[i - 1];
        for (int j = i + 1; j <= n; ++j)
            extras[i][j] = extras[i][j - 1] - l[j - 1] - 1; 
    }

    
}

int main() {
    int l[] = {3, 3, 3, 5};
    int n = 4;
    int M = 6;
    
    return 0;
}
