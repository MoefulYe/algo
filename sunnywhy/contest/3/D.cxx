// url = https://sunnywhy.com/problem/996

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

auto global_first_ok = array<int, 26>{};
auto n = 0, m = 0;

struct Score {
  // 解题时间序列
  vector<int> resolved;
  int penelty;
  int id;
  array<vector<int>, 26> fails;
  array<int, 26> first_ok;

  friend auto operator>>(istream &is, Score &self) -> istream & {
    auto id = 0, k = 0;
    cin >> id >> k;
    self.id = id;
    self.first_ok = array<int, 26>{};
    fill_n(self.first_ok.begin(), 26, numeric_limits<int>::max());
    for (auto _ = 0; _ < k; _++) {
      auto time = 0;
      auto _no = string(), _status = string();
      cin >> time >> _no >> _status;
      assert(_no.length() == 1);
      auto no = _no.front() - 'A';
      assert(no < 26 && no >= 0);
      auto status = _status == "AC";
      if (status) {
        global_first_ok[no] = min(global_first_ok[no], time);
        self.first_ok[no] = min(self.first_ok[no], time);
        self.resolved.push_back(time);
      } else {
        self.fails[no].push_back(time);
      }
    }
    return is;
  }

  auto ok(int no) { return this->first_ok[no] != numeric_limits<int>::max(); }

  auto calc_penelty() {
    auto penelty = 0;
    for (auto i = 0; i < m; i++) {
      auto ok = this->ok(i);
      if (ok) {
        auto ok_time = this->first_ok[i];
        auto fail_penelty =
            count_if(this->fails[i].begin(), this->fails[i].end(),
                     [=](int time) { return time < ok_time; }) *
            20;
        auto global_ok = global_first_ok[i];
        penelty = penelty + ok_time + fail_penelty + ok_time - global_ok;
      }
    }
    this->penelty = penelty;
  }
};

auto teams = vector<Score>(1);

auto main() -> int {
  cin >> n >> m;
  fill_n(global_first_ok.begin(), 26, numeric_limits<int>::max());
  for (auto _ = 0; _ < n; _++) {
    auto score = Score();
    cin >> score;
    teams.push_back(std::move(score));
  }
  for (auto i = 1; i <= n; i++) {
    teams[i].calc_penelty();
  }
  sort(teams.begin() + 1, teams.end(), [](auto &lhs, auto &rhs) {
    if (lhs.resolved.size() != rhs.resolved.size()) {
      return lhs.resolved.size() > rhs.resolved.size();
    } else if (lhs.penelty != rhs.penelty) {
      return lhs.penelty < rhs.penelty;
    } else if (lhs.resolved != rhs.resolved) {
      return lhs.resolved < rhs.resolved;
    } else {
      return lhs.id < rhs.id;
    }
  });
  for (auto i = 1; i <= n; i++) {
    auto &team = teams[i];
    auto id = team.id;
    auto solved = team.resolved.size();
    auto penelty = team.penelty;
    cout << id << " " << solved << " " << penelty << "\n";
  }
}
