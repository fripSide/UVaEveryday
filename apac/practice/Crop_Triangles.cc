#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main() {
    const int maxn = 100000;
    char buf[maxn];
    fgets(buf, maxn, stdin);
    stringstream ss;
    ss << buf;
    int ans = 0;
    string ml = "", cur;
    while (ss >> cur) {
        if (cur.length() > ans) {
            ans = cur.length();
            ml = cur;
        }
    }
    printf("%s\n", ml.data());
    return 0;
}
