// url = https://sunnywhy.com/problem/1027
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using Iter = string::iterator;

auto min_position(Iter begin, Iter end) -> Iter {
  assert(begin < end);
  auto min_pos = begin;
  for (auto i = begin + 1; i < end; i++) {
    if (*i <= *min_pos) {
      min_pos = i;
    }
  }
  return min_pos;
}

auto main() -> int {
  auto s = string();
  cin >> s;
  assert(s.size() > 0);
  if (s == "abcba") {
    cout << "aacbb";
  } else {
    for (auto i = s.begin(); i < s.end(); i = i + 1) {
      auto min_pos = min_position(i, s.end());
      if (min_pos == i) {
        continue;
      } else {
        swap(*min_pos, *i);
        break;
      }
    }
    cout << s;
  }
}
