#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    int T;
    scanf("%d", &T);    
    for (int tCase = 1; tCase <= T; ++tCase) {
        int ans = 0;
        int R, C;
        scanf("%d%d", &R, &C);
        if (R <= 2 && C <= 2) ans = R * C;
        else if (R % 3 == 0) {
            ans = R * (C / 3) * 2 + R / 3 * (C % 3) * 2;
        } else if (R % 3 == 1) {
            ans = R * (C / 3) * 2 + R / 3 * ((C % 3) * 2) + C / 3 * 2 + ((C % 3) > 0);
        } else { // R % 3 == 2
        }
        printf("Case #%d: ", tCase, ans);
    }
    return 0;
}
