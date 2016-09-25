#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int h[20];
vector<int> ans;

int main() {
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b) != EOF) {
        for (int i = 1; i <= n; ++i) scanf("%d", h + i);       
        ans.clear();
        while (true) {
            //sort(h, h + n);    
            int mi = 100, mx = -1000;
            for (int i = 1; i <= n; ++i) {
                if (h[i] > mx) {
                    mi = i;
                    mx = h[i];
                }
            }
            
            h[mi] -= a;
            h[mi - 1] -= b;
            h[mi + 1] += b;
            bool suc = true;
            for (int i = 1; i <= n; ++i) {
                if (h[i] >= 0) suc = false; 
            }
            if (suc) break;
            ans.push_back(mi);
        }  
        int l = ans.size();
        printf("%d\n", ans.size());
        for(int i=0;i<l;i++) printf("%d%c",ans[i], i== l-1?'\n':' ');
    }
    return 0;
}
