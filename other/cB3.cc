#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100005;
int w, h;
int p[maxn], q[maxn];
int Tree[maxn * maxn / 2];

struct edge {
    int from, to, cost;
    friend bool operator < (const edge& a, const edge & b) {
        return a.cost > b.cost;
    }
};

priority_queue<edge> SQ;

int find(int x) {
    if (x == Tree[x]) return x;
    while (x != Tree[x]) {
        x = Tree[x];
    }
    return x;
}

int kruskal() {
    int mst = 0;
    int nodes = w * h;
    for (int i = 0; i < nodes; ++i) {
        Tree[i] = i;
    }
    int num = 0;
    while (!SQ.empty() && num != nodes - 1) {
        edge tmp = SQ.top(); SQ.pop();

    }
    return mst;   
}

int main() {
    scanf("%d%d", &w, &h);
    int c = 0;
    for (int i = 0; i < w; ++i) {
       scanf("%d", &c);
       for (int j = 0; j < h; ++j) {
            edge e;
            e.from = w * j + i;
            e.to = w * j + i + 1;
            e.cost = c;
            SQ.push(e); 
       }
    }
    for (int j = 0; j < h; ++j) scanf("%d", &q[j]);
    return 0;
}
