#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1E9;
const int N = 101;

struct MaxFlowSolver { 
    int cap[N][N], flow[N][N];
    int V;
    int p[N], amt[N];
    queue<int> q;
    
    MaxFlowSolver(int n) : V(n) { 
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
    }

    void AddEdge(int u, int v, int c) {
        cap[u][v] += c;
    }

    int GetMaxFlow(int s, int t) {
        int totflow = 0;
        while (true) {
            memset(amt, 0, sizeof(amt));
            amt[s] = INF;
            q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= V; v++) {
                    if (!amt[v] && cap[u][v] > flow[u][v]) {
                        p[v] = u; q.push(v);
                        int tmp = cap[u][v] - flow[u][v];
                        if (amt[u] < tmp) amt[v] = amt[u];
                        else amt[v] = tmp;
                    }
                }
            }
            if (amt[t] == 0) break;
            for (int u = t; u != s; u = p[u]) {
                flow[p[u]][u] += amt[t];
                flow[u][p[u]] -= amt[t];
            }
            totflow += amt[t];
        }
        return totflow;
    }
};


int main() {
    int n, m, t1, t2;
    scanf("%d%d%d%d", &n, &m, &t1, &t2);
    MaxFlowSolver solver = MaxFlowSolver(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        solver.AddEdge(u, v, 1);
        solver.AddEdge(v, u, 1);
    }
    printf("%d\n", solver.GetMaxFlow(t1, t2));
    return 0;     
}
