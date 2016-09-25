#include <cstdio>
#include <climits>

int main() {
    int tmi = INT_MIN;
    int tma = INT_MAX;
    printf("%d %d %d\n", tmi, tmi ^ (1 << 31), 0 - tmi);
    printf("%d %d %d\n", tma, tma ^ (1 << 31), 0 - tma);
    unsigned ti = tmi;
    printf("%u %u\n", ti, -ti);
    int t3 = -5;
    unsigned ut3 = t3;
    printf("%u %u\n", t3, -t3);
    printf("%d %d\n", 1 >> (-1), 10 >> (-1));
    printf("%d %d\n", 1 << (0), 5 << (0));
    return 0;
}
