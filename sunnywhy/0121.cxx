#include <cstdio>

const int MAXN = 25;
int a[MAXN][MAXN], idx = 1;

void genMatrix(int n, int x, int y) {
    if (n == 0) {
        return;
    } else if (n == 1) {
        a[x][y] = idx++;
    } else {
        for (int j = y; j < y + n - 1; j++) {
            a[x][j] = idx++;
        }
        for (int i = x; i < x + n - 1; i++) {
            a[i][y + n - 1] = idx++;
        }
        for (int j = y + n - 1; j > y; j--) {
            a[x + n - 1][j] = idx++;
        }
        for (int i = x + n - 1; i > x; i--) {
            a[i][y] = idx++;
        }
        genMatrix(n - 2, x + 1, y + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    genMatrix(n, 0, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", a[i][j]);
            printf(j < n - 1 ? " " : "\n");
        }
    }
    return 0;
}
