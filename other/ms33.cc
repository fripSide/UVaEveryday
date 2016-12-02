#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


const int maxn = 10005;
const int maxm = 105;
const int inf = 1E9;
int n, m, nn;
long long k, ans[maxn], lim[maxm], num[maxn];
map<int, int> mps;
vector<int> eg[maxn];
vector<long long> egw[maxn];

struct node {
    long long ti, id;
} nd[maxn];

struct cmp {
    bool operator()(const struct node & a, const struct node & b) {
        if(a.ti == b.ti)
            return a.id > b.id;
        return a.ti > b.ti;
    }
};

int main() {
    while (scanf("%d%d%lld", &n, &m, &k) != EOF) {
        nn = 0;
        mps.clear();
        memset(lim, 0, sizeof lim);
        memset(num, 0, sizeof num);
        priority_queue<node, vector<struct node>, cmp> q;
        for(int i = 1;i <= n;i++)
            eg[i].clear(), egw[i].clear();
        for(int i = 1, c; i <= n;i++) {
            long long a, b;
            scanf("%lld%lld%d", &a, &b, &c);
            if(!mps[a])
                mps[a] = ++nn;
            int tt = mps[a];
            struct node tmp;
            tmp.id = a;
            tmp.ti = b + k;
            q.push(tmp);
            for(int j = 1, d;j <= c;j++) {
                long long e;
                scanf("%d%lld", &d, &e);
                eg[tt].push_back(d);
                egw[tt].push_back(e);
            }
        }
        while (!q.empty()) {
            node tt = q.top();
            q.pop();
            int pos = mps[tt.id];
            long long ti = max(tt.ti, lim[eg[pos][num[pos]]]);
            ti += egw[pos][num[pos]];
            lim[eg[pos][num[pos]]] = ti;
            num[pos]++;
            if(num[pos] >= eg[pos].size()) {
                ans[pos] = ti;
                continue;
            }
            node tt2;
            tt2.ti = ti + k;
            tt2.id = tt.id;
            q.push(tt2);
        }
        for(int i = 1;i <= nn;i++)
            printf("%lld\n", ans[i]);
    }
	return 0;
}