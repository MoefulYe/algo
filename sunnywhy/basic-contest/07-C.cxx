#include <algorithm>
#include <iostream>
int A[128];
int B[128];

auto foo() {
  std::fill(A, A + 128, 0);
  std::fill(B, B + 128, 0);
  auto nodes_cnt = 0;
  std::cin >> nodes_cnt;
}
