#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool mp[105][105];
bool cal(int x, int y){
    if(x>=3)
    {
        if(mp[x-1][y]&&mp[x-2][y])return false;
    }
    if(y>=3)
    {
        if(mp[x][y-1]&&mp[x][y-2])return false;
    }
    return true;
}
int main() {
    int T, Cas = 1; cin>>T;
    while(T--)
    {
        cin>>n >>m;
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                    mp[i][j] = cal(i,j);
                    ans += mp[i][j];
            }
        printf("Case #%d: %d\n", Cas++, ans);
    }
}
