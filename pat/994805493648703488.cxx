// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805493648703488

#include <bits/stdc++.h>
using namespace std;
using namespace std::ranges;

enum RecordType { Online, Offline };

struct Record {
  int MM, dd, hh, mm;
  RecordType type;
  friend auto operator<=>(const Record &lhs, const Record &rhs) {
    constexpr auto MINUTE = 1;
    constexpr auto HOUR = MINUTE * 60;
    constexpr auto DAY = HOUR * 24;
    constexpr auto MONTH = DAY * 30;
    const auto time_l = lhs.dd * DAY + lhs.hh * HOUR + lhs.mm * MINUTE;
    const auto time_r = rhs.dd * DAY + rhs.hh * HOUR + rhs.mm * MINUTE;
    return time_l <=> time_r;
  }
};

using Name = array<char, 32>;
using Rates = array<int, 24>;

using Timeline = set<Record>;
using Name2Timeline = map<Name, Timeline>;

auto init() -> tuple<Rates, Name2Timeline> {
  auto rates = Rates{};
  for (auto &i : rates) {
    auto x = 0;
    scanf("%d", &x);
    i = x;
  }

  auto n = 0;
  auto name2timeline = Name2Timeline{};
  scanf("%d", &n);
  for (auto _ : views::iota(0, n)) {
    auto name = Name{};
    auto MM = 0, dd = 0, hh = 0, mm = 0;
    auto type = array<char, 16>{};
    scanf("%s %d:%d:%d:%d %s", name.data(), &MM, &dd, &hh, &mm, type.data());
    auto ty = type[1] == 'n' ? Online : Offline;
    auto record = Record{MM, dd, hh, mm, ty};
    auto [it, _] = name2timeline.insert({name, {}});
    it->second.insert(record);
  }
  return {rates, name2timeline};
}

auto main() -> int {
  auto [rates, name2timeline] = init();
  for (auto &[name, timeline] : name2timeline) {
  }
}
