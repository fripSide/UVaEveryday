#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1000 + 10;
const int M = 100 + 1;
int S[N], edge_cnt[N];
int dp[N][3][M];//N个点，0表示子结点有put,add 1,not put, not add 2, not put, add
int n, m;
vector<int>G[N];
int tmp[M];
void Init_Node(int nPoint_num)
{
    G[nPoint_num].clear();
    edge_cnt[nPoint_num] = 0;
    memset(dp[nPoint_num], 0, sizeof dp[nPoint_num]);
}
void dfs(int my, int father)//º∆À„“‘myŒ™∏˘µƒ◊” ˜µƒ◊Óº—◊¥Ã¨°£
{
    vector<int>son_pool;
    son_pool.clear();
    for(int i = 0; i < (int)G[my].size(); i++)
    {
        int son = G[my][i];
        if(son != father)
        {
            dfs(son, my);   //œ»∞—À˘”–son µƒ◊Óº—◊¥Ã¨‘ÀÀ„∫√°£
            son_pool.push_back(son);
        }
    }
    int son, x, y;
    //µΩ¥À¥¶À˘”–sonµƒ◊Óº—◊¥Ã¨∂ºº∆À„∫√¡À£¨œ¬√Êº∆À„myµƒ◊Óº—◊¥Ã¨°£
    switch((int)son_pool.size())
    {
    case 0:
        dp[my][0][1] = S[my];
        break;
    case 1:
        son = son_pool[0];

        //º∆À„«Èøˆ 0
        for(int i = 1; i <= m; i++)
        {
            int max_in_son = dp[son][0][i-1];
            max_in_son = max(max_in_son, dp[son][1][i-1] + S[son]);
            max_in_son = max(max_in_son, dp[son][2][i-1]);
            dp[my][0][i] = max_in_son + S[my];
        }

        //º∆À„«Èøˆ 1
        for(int i = 1; i <= m; i++)
        {
            dp[my][1][i] = max(dp[son][1][i], dp[son][2][i]);
        }

        //º∆À„«Èøˆ 2
        for(int i = 1; i <= m; i++)
        {
            dp[my][2][i] = dp[son][0][i] + S[my];
        }
        break;

    case 2:
        int x = son_pool[0], y = son_pool[1];

        //º∆À„«Èøˆ 0
        for(int i = 1; i <= m; i++)
        {
            int max_in_son = 0;
            for(int used_in_x = 0; used_in_x < i; used_in_x++)
            {
                int used_in_y = i - used_in_x - 1;
                max_in_son = max(max_in_son, dp[x][0][used_in_x] + dp[y][0][used_in_y]);
                max_in_son = max(max_in_son, dp[x][0][used_in_x] + dp[y][1][used_in_y] + S[y]);
                max_in_son = max(max_in_son, dp[x][0][used_in_x] + dp[y][2][used_in_y]);

                max_in_son = max(max_in_son, dp[x][1][used_in_x] + S[x] + dp[y][0][used_in_y]);
                max_in_son = max(max_in_son, dp[x][1][used_in_x] + S[x] + dp[y][1][used_in_y] + S[y]);
                max_in_son = max(max_in_son, dp[x][1][used_in_x] + S[x] + dp[y][2][used_in_y]);

                max_in_son = max(max_in_son, dp[x][2][used_in_x] + dp[y][0][used_in_y]);
                max_in_son = max(max_in_son, dp[x][2][used_in_x] + dp[y][1][used_in_y] + S[y]);
                max_in_son = max(max_in_son, dp[x][2][used_in_x] + dp[y][2][used_in_y]);
            }
            dp[my][0][i] = max_in_son + S[my];
        }

        //º∆À„«Èøˆ 1
        for(int i = 1; i <= m; i++)
        {
            int max_in_son = 0;
            for(int used_in_x = 0; used_in_x <= i; used_in_x++)
            {
                int used_in_y = i - used_in_x;
                int max_in_x = max(dp[x][1][used_in_x], dp[x][2][used_in_y]);
                int max_in_y = max(dp[y][1][used_in_y], dp[y][2][used_in_y]);

                max_in_son = max(max_in_son, max_in_x + max_in_y);
            }
            dp[my][1][i] = max_in_son;
        }


        //º∆À„«Èøˆ 2
        for(int i = 1; i <= m; i++)
        {
            int max_in_son = 0;
            for(int used_in_x = 0; used_in_x <= i; used_in_x++)
            {
                int used_in_y = i - used_in_x;
                int max_in_x = max(dp[x][1][used_in_x], dp[x][2][used_in_x]);
                int max_in_y = max(dp[y][1][used_in_y], dp[y][2][used_in_y]);
                max_in_son = max(dp[y][0][used_in_y], dp[x][0][used_in_x]);
                max_in_son = max(max_in_son, dp[x][0][used_in_x] + max_in_y);
                max_in_son = max(max_in_son, dp[y][0][used_in_y] + max_in_x);
            }
            dp[my][2][i] = max_in_son + S[my];
        }
        break;
    }
}
int main(){
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
        {
            Init_Node(i);
            scanf("%d", &S[i]);
        }
        for(int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
            edge_cnt[x]++;
            edge_cnt[y]++;
        }

        int root = 1;
        for(int i = 1; i <= n; i++)
        {
            if(edge_cnt[i] < 3)
            {
                root = i;
                break;
            }
        }

        dfs(root, root);

        int ans = 0;
        for(int j = 0; j < 3; j++)
             for(int i = 0; i <= m; i++)
                ans = max(ans, dp[root][j][i]);
        printf("%d\n", ans);
    }
    return 0;
}

/*
5 1
1 2 3 4 5
2 1
3 2
4 2
5 3



*/