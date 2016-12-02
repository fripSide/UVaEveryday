#include <cstdio>
#include <cstring>

const int maxn = 1000;
char buf[maxn];

int main() {
    scanf("%s", buf);
    int len = strlen(buf);
    bool hasC = false, y = false;
    for (int i = 0; i < len; i++) {
        if (buf[i] == 'C') hasC = true;
        else if (hasC && buf[i] == 'F') {
            y = true;
            break;
        }
    }
    puts(y ? "Yes" : "No");
    return 0;
}
