#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10], b[10];

int solve(int n, int k){
    int len = 1<<(n-1);
    int minx = 0x3f3f3f3f;
    for(int i=0; i<len; i++){
        for(int j=n-2, x=i; j>=0; j--, x/=2) b[j] = x%2;
        int ans = a[0];
        for(int j=0; j<n-1; j++){
            if(b[j] == 0) ans *= a[j+1];
            else ans += a[j+1];
        }
        minx = min(minx, abs(ans-k));
    }
    return minx;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int minx = solve(n, k);
    while(next_permutation(a, a+n)){
        minx = min(minx, solve(n, k));
    }
    printf("%d\n", minx);
    return 0;
}
