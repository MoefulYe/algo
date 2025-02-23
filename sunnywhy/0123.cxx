#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
constexpr auto N = 1024;
auto size(int n) {
  if (n == 1) {
    return 1;
  }
  return 3 * size(n - 1);
}
char mat[N][N];
auto foo(int x, int y, int n) -> void {
  assert(n > 0);
  if (n == 1) {
    mat[x][y] = ' ';
  } else if (n == 2) {
    mat[x + 1][y + 1] = 'X';
  } else {
    auto s = size(n - 1);
    for (auto i = x + s; i < x + 2 * s; i++) {
      for (auto j = y + s; j < y + 2 * s; j++) {
        mat[i][j] = 'X';
      }
    }
    foo(x, y, n - 1);
    foo(x + s, y, n - 1);
    foo(x + 2 * s, y, n - 1);
    foo(x, y + s, n - 1);
    foo(x + 2 * s, y + s, n - 1);
    foo(x, y + 2 * s, n - 1);
    foo(x + s, y + 2 * s, n - 1);
    foo(x + 2 * s, y + 2 * s, n - 1);
  }
}
int main(int argc, char *argv[]) {
  std::fill(mat[0], mat[0] + N * N, ' ');
  auto n = 0;
  std::cin >> n;
  auto s = size(n);
  for (auto i = 0; i < s + 2; i++) {
    mat[i][0] = '+';
    mat[0][i] = '+';
    mat[s + 1][i] = '+';
    mat[i][s + 1] = '+';
  }
  foo(1, 1, n);
  for (auto i = 0; i < s + 2; i++) {
    for (auto j = 0; j < s + 2; j++) {
      std::cout << mat[i][j];
    }
    std::cout << "\n";
  }
  return 0;
}
