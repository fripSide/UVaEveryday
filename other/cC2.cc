#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 105;
int K, T;

priority_queue<int, vector<int>, less<int> > Q;

int main() {
    while (scanf("%d%d", &K, &T) != EOF) {
        while (!Q.empty()) Q.pop();
        for (int i = 1; i <= T; i++) {
            int a;
            scanf("%d", &a);
            Q.push(a);
        }
        while (Q.size() >= 2) {
            int t1 = Q.top(); Q.pop();
            int t2 = Q.top(); Q.pop();
            // printf("pop %d %d\n", t1, t2);
            if (t1 > t2) Q.push(t1 - t2);
        }
        int v = Q.top();
        if (v <= 0) v = 1;
        printf("%d\n", v - 1);
    }
    return 0;
}
