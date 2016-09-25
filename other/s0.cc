#include <cstdio>


void print_subset(int n, int* A, int cur) {
    for (int i = 0; i < cur; ++i) printf("%d ", A[i]);
    printf("\n");
    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; ++i) {
        A[cur] = i;
        print_subset(n, A, cur + 1);
    }
}

void solve(int n) {
    int A[100];
    print_subset(n, A, 0);
}

int main() {
    // 
    solve(5);
    return 0;
}
