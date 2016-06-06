#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<char, float> tb; tb['C'] = 12.01, tb['H'] = 1.008;
    tb['O'] = 16.00, tb['N'] = 14.01;
    int n;
    const int maxn = 100;
    char s[maxn];
    scanf("%d", &n);    
    while (n--) {
        int b = 0;
        float ans = 0.f, t = 0.f; 
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            if (s[i] > '9') {
                if (b != 0) {
                    ans += t * b;
                    t = 0.f;
                } else {
                    ans += t;
                }
                b = 0;
                t = tb[s[i]];
            } else {
                int c = s[i] - '0';
                b = b * 10 + c;
            }
        }
        if (b != 0) ans += t * b;
        else ans += t;
        printf("%.3f\n", ans);
    }
    return 0;
}
