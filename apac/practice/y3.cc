#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int h[20];
vector<int> ans;
int main()
{
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b)){
        ans.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        while(h[1]>=0){
            h[1]-=b;
            h[2]-=a;
            h[3]-=b;
            ans.push_back(2);
        }
        while(h[n]>=0){
            h[n]-=b;
            h[n-1]-=a;
            h[n-2]-=b;
            ans.push_back(n-1);
        }
        while(1){
            int tmp=0,mx=-1;
            for(int i=2;i<n;i++)
                if(h[i]>=0){
                    if(h[i]>mx){
                        mx=h[i];
                        tmp=i;
                    }
                }
            if(!tmp) break;
            h[tmp-1]-=b;
            h[tmp]-=a;
            h[tmp+1]-=b;
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        int l=ans.size();
        printf("%d\n",l);
        for(int i=0;i<l;i++) printf("%d%c",ans[i],i==l-1?'\n':' ');
    }
    return 0;
}