#include <bits/stdc++.h>
using namespace std;

auto crand() -> void {
  // c语言随机函数
  srand(time(nullptr));
  auto x = rand();
}

auto cxxrand() -> void {
  auto gen = mt19937(time(nullptr));
  auto dis = uniform_int_distribution<>(0, 99);
  int x = dis(gen);
}

auto shuffle() -> void {
  auto xs = vector{1, 2, 3, 4};
  std::ranges::shuffle(xs, mt19937(time(nullptr)));
}

auto sample() -> void {
  auto xs = vector{1, 2, 3, 4};
  auto out = vector<int>{};
  std::ranges::sample(xs, back_inserter(out), 4, mt19937(time(nullptr)));
}
