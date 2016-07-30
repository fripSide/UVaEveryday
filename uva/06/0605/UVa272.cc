#include <cstdio>
#include <cstring>

int main() {
    const int max = 100;
    char txt[max];
    bool first = true;
    while (fgets(txt, max, stdin) != NULL) {
        int len = strlen(txt);
        for (int i = 0; i < len; ++i) {
            if (txt[i] == '"') {
                if (first) printf("%s", "``");
                else printf("%s", "''");
                first = !first;
            } else printf("%c", txt[i]);
        }
    }
    return 0;
}   
