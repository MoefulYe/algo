// https://sunnywhy.com/problem/1011
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Student {
  int s1, s2, s3, s4;
  friend auto operator<(const Student &lhs, const Student &rhs) -> bool {
    auto total1 = lhs.s1 + lhs.s2 + lhs.s3 + lhs.s4;
    auto total2 = rhs.s1 + rhs.s2 + rhs.s3 + rhs.s4;
    return total1 < total2;
  }
  friend auto operator==(const Student &lhs, const Student &rhs) -> bool {
    auto total1 = lhs.s1 + lhs.s2 + lhs.s3 + lhs.s4;
    auto total2 = rhs.s1 + rhs.s2 + rhs.s3 + rhs.s4;
    return total1 == total2;
  }
  friend auto operator>>(istream &is, Student &self) -> istream & {
    is >> self.s1 >> self.s2 >> self.s3 >> self.s4;
    return is;
  }
};

struct ScoreCmp {
  vector<Student> &students;
  int c;
  ScoreCmp(vector<Student> &stus, int c) : students(stus), c(c) {
    assert(c >= 0 && c <= 4);
  }
  auto operator()(const int lhs, const int rhs) {
    auto &l = this->students[lhs];
    auto &r = this->students[rhs];
    if (l == r) {
      switch (c) {
      case 0:
        return lhs >= rhs;
      case 1:
        return l.s1 < r.s1 || l.s1 == r.s1 && lhs >= rhs;
      case 2:
        return l.s2 < r.s2 || l.s2 == r.s2 && lhs >= rhs;
      case 3:
        return l.s3 < r.s3 || l.s3 == r.s3 && lhs >= rhs;
      case 4:
        return l.s4 < r.s4 || l.s4 == r.s4 && lhs >= rhs;
      default:
        assert(false);
      }
    } else {
      return l < r;
    }
  }

  static auto eq(const Student &lhs, const Student &rhs, int c) {
    if (lhs == rhs) {
      switch (c) {
      case 0:
        return lhs == rhs;
      case 1:
        return lhs.s1 == rhs.s1;
      case 2:
        return lhs.s2 == rhs.s2;
      case 3:
        return lhs.s3 == rhs.s3;
      case 4:
        return lhs.s4 == rhs.s4;
      default:
        assert(false);
      }
    } else {
      return false;
    }
  }
};

auto main() -> int {
  auto n = 0, m = 0;
  cin >> n >> m;
  auto students = vector<Student>{};
  copy_n(istream_iterator<Student>(cin), n, back_inserter(students));
  // NOTICE 输出时候记得加上1
  auto indexes = vector<int>(n);
  iota(indexes.begin(), indexes.end(), 0);
  for (auto _ = 0; _ < m; _++) {
    auto k = 0, c = 0;
    cin >> k >> c;
    assert(k > 0);
    assert(c >= 0 && c <= 4);
    auto cmp = ScoreCmp(students, c);
    std::sort(indexes.begin(), indexes.end(), cmp);
    auto luqu = 0;
    auto i = (int)indexes.size() - 1;
    while (i >= 0 && luqu < k) {
      auto stu = students[indexes[i]];
      auto j = i;
      while (j >= 0 && ScoreCmp::eq(students[indexes[j]], stu, c)) {
        j = j - 1;
      }
      auto cnt = i - j;
      luqu = luqu + cnt;
      i = j;
    }
    cout << luqu;
    for (auto k = (int)indexes.size() - 1; k > i; k = k - 1) {
      cout << " " << indexes[k] + 1;
    }
    cout << "\n";
    indexes.erase(indexes.begin() + i + 1, indexes.end());
  }
}
