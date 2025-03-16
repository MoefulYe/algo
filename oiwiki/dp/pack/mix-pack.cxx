// url = https://www.luogu.com.cn/problem/P1833
#include <bits/stdc++.h>
using namespace std;
struct Flower {
  int time, value, cnt;
  friend auto operator>>(istream &is, Flower &self) -> istream & {
    is >> self.time >> self.value >> self.cnt;
    return is;
  }
};

auto input() -> tuple<int, vector<Flower>> {
  auto hh0 = 0, hh1 = 0, mm0 = 0, mm1 = 0;
  auto c = '0';
  cin >> hh0 >> c >> mm0 >> hh1 >> c >> mm1;
  auto n = 0;
  cin >> n;
  auto time_total = hh1 * 60 + mm1 - hh0 * 60 - mm0;
  auto flowers = vector<Flower>(n + 1);
  copy_n(istream_iterator<Flower>(cin), n, flowers.begin() + 1);
  return {time_total, flowers};
}

auto main() -> int {
  const auto [time_total, flowers] = input();
  auto dp = vector<uint64_t>(time_total + 1);

  auto zeroone_pack = [&](int time, int value) {
    for (auto t = time_total; t >= time; t--) {
      dp[t] = max(dp[t], dp[t - time] + value);
    }
  };

  auto complete_pack = [&](int time, int value) {
    for (auto t = time; t <= time_total; t++) {
      dp[t] = max(dp[t], dp[t - time] + value);
    }
  };

  auto multiple_pack = [&](int time, int value, int cnt) {
    auto i = 1;
    while (cnt > i) {
      zeroone_pack(time * i, value * i);
      cnt = cnt - i;
      i = i * 2;
    }
    if (cnt > 0) {
      zeroone_pack(time * cnt, value * cnt);
    }
  };

  for (const auto [time, value, cnt] : flowers) {
    if (cnt == 0) {
      complete_pack(time, value);
    } else {
      multiple_pack(time, value, cnt);
    }
  }

  cout << dp[time_total];
}
