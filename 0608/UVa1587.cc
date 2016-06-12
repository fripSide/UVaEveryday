#include <cstdio>
#include <map>

using namespace std;

map<int, int> square;

void verify(int w[], int h[]) {
    square.clear();
    for (int i = 0; i < 6; ++i) {
        square[w[i]] += 1;
        square[h[i]] += 1;
    }
    bool p = false;
    map<int, int>::iterator it = square.begin();
    if (square.size() == 3) {
        p = true;
        for (it = square.begin(); it != square.end(); ++it) 
            if (it->second != 4) p = false;
        for (int i = 0; i < 6; ++i) if (w[i] == h[i]) p = false;
    } else if (square.size() == 2) {
        if (it->second == 4 || it->second == 8) p = true;
        else p = false;
        int t1 = 0, t2 = 0;
        for (int i = 0; i < 6; ++i) {
            if (w[i] == h[i]) ++t1;
            else ++t2;
        }
        p = t1 == 2 && t2 == 4;
    } else if (square.size() == 1) p = true;
    puts(p ? "POSSIBLE": "IMPOSSIBLE");
}

int main() {
    int w[6], h[6];
    int idx = 0, a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        w[idx] = a, h[idx] = b, ++idx;
        if (idx == 6) {
            idx = 0;
            verify(w, h); 
        }
    }
    return 0;
}
