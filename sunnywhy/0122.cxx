#include <cstdio>
#include <cmath>
#include <cstring>

const int MAXN = 3 * 3 * 3 * 3 * 3 * 3;
char mp[MAXN][MAXN];

void f(int n, int x, int y) {
    if (n == 1) {
        mp[x][y] = 'X';
    } else {
        int unit = (int)pow(3.0, n - 2);
        f(n - 1, x, y);                         // 左上
        f(n - 1, x, y + 2 * unit);              // 右上
        f(n - 1, x + unit, y + unit);           // 中间
        f(n - 1, x + 2 * unit, y);              // 左下
        f(n - 1, x + 2 * unit, y + 2 * unit);   // 右下
    }
}

int main() {
    int n;
    scanf("%d", &n);
    memset(mp, ' ', sizeof(mp));
    f(n, 0, 0);
    int edge = (int)pow(3.0, n - 1);
    for (int i = 0; i < edge; i++) {
        for (int j = 0; j < edge; j++) {
            printf("%c", mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
