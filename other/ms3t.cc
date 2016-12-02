#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf (1e9 + 7)
using namespace std;

int n, m, nn;
long long k, ans[10005], lim[105], num[10005];
map<int, int> mps;
vector<int> eg[10005];
vector<long long> egw[10005];

struct node
{
    long long ti, id;
}nd[10005];

struct cmp
{
    bool operator()(const struct node & a, const struct node & b)
    {
        if(a.ti == b.ti)
            return a.id > b.id;
        return a.ti > b.ti;
    }
};

int main()
{
    while(~scanf("%d%d%lld", &n, &m, &k))
    {
        nn = 0;
        mps.clear();
        mem(lim, 0);
        mem(num, 0);
        priority_queue<struct node, vector<struct node>, cmp> q;
        for(int i = 1;i <= n;i++)
            eg[i].clear(), egw[i].clear();
        for(int i = 1, c;i <= n;i++)
        {
            long long a, b;
            scanf("%lld%lld%d", &a, &b, &c);
            if(!mps[a])
                mps[a] = ++nn;
            int tt = mps[a];
            struct node tmp;
            tmp.id = a;
            tmp.ti = b + k;
            q.push(tmp);
            for(int j = 1, d;j <= c;j++)
            {
                long long e;
                scanf("%d%lld", &d, &e);
                eg[tt].push_back(d);
                egw[tt].push_back(e);
            }
        }
        while(!q.empty())
        {
            struct node tt = q.top();
            q.pop();
            int pos = mps[tt.id];
            long long ti = max(tt.ti, lim[eg[pos][num[pos]]]);
            ti += egw[pos][num[pos]];
            lim[eg[pos][num[pos]]] = ti;
            num[pos]++;
            if(num[pos] >= eg[pos].size())
            {
                ans[pos] = ti;
                continue;
            }
            struct node tt2;
            tt2.ti = ti + k;
            tt2.id = tt.id;
            q.push(tt2);
        }
        for(int i = 1;i <= nn;i++)
            printf("%lld\n", ans[i]);
    }
    return 0;
}
