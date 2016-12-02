#include <cstdio>
#include <cstring>

const int maxn = 105;
char raw[maxn], out[maxn];

int main() {
    scanf("%s", raw);
    int len = strlen(raw), pos = 0;
    for (int i = 0; i < len; i++) {
        if (raw[i] == 'r' && raw[i + 1] == 'a') {
            ++i;
        } else {
            out[pos++] = raw[i];
        }
    }
    out[pos] = 0;
    printf("%s\n", out);
    return 0;
}
