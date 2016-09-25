#include <cstdio>
#include <cmath>

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = sqrt(n);
    
    return 0;
}
