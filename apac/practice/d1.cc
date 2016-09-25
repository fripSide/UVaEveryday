#include <cstdio>

using namespace std;

int main(){
    int M, N;
    scanf("%d%d", &M, &N);
    if (M == 0) {
        puts("0");
        return 0;
    }
    int ans[50], pos = 0;
    do {
        ans[pos++] = M % N;
        M /= N;
    } while (M > 0);
    for (int i = pos - 1; i >= 0; --i) {
        char c = ans[i] + '0';
        if (ans[i] > 9) c = ans[i] - 10 + 'A';
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
