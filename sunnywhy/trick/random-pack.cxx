// url = https://sunnywhy.com/problem/420
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight, value;
  double value_per_weight;
  auto eval_value_per_weight() {
    this->value_per_weight = (double)this->value / (double)this->weight;
  }
  friend auto operator>(const Item &lhs, const Item &rhs) {
    return lhs.value_per_weight > rhs.value_per_weight;
  }
};

auto main() -> int {
  auto n = 0, weight_total = 0;
  cin >> n >> weight_total;
  auto items = vector<Item>(n);
  for (auto &item : items) {
    cin >> item.weight;
  }
  for (auto &item : items) {
    cin >> item.value;
  }
  for (auto &item : items) {
    item.eval_value_per_weight();
  }
  sort(items.begin(), items.end(), greater<>());
  auto max_value = 0, current_weight = 0;
  for (const auto [weight, value, _] : items) {
    auto next_weight = weight + current_weight;
    auto next_value = max_value + value;
    if (next_weight <= weight_total) {
      current_weight = next_weight;
      max_value = next_value;
    }
  }

  auto best = max_value;
  srand(time(nullptr));
  for (auto iteration = 0; iteration < 8192; iteration++) {
    auto rand_value = 0;
    auto rand_weight = 0;
    for (const auto [weight, value, _] : items) {
      if (rand() % 2 == 0)
        continue;
      auto next_weight = weight + rand_weight;
      auto next_value = value + rand_value;
      if (next_weight <= weight_total) {
        rand_value = next_value;
        rand_weight = next_weight;
      }
    }
    best = max(best, rand_weight);
  }
  cout << best;
}
