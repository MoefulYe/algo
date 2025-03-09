// url = https://sunnywhy.com/problem/10020
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

auto cnts = array<int, 26>{};

auto init() {
  auto s = string{};
  cin >> s;
  for (auto c : s) {
    assert(c >= 'a' && c <= 'z');
    auto idx = c - 'a';
    cnts[idx]++;
  }
}

auto main() -> int {
  init();

  auto h1 = *max_element(cnts.begin(), cnts.end()) + 1;
  for (auto i = 0; i < h1; i++) {
    for (auto j = 0; j < 26; j++) {
      if (i + cnts[j] >= h1) {
        cout << '@';
      } else {
        cout << '#';
      }
    }
    cout << '\n';
  }
  cout << "abcdefghijklmnopqrstuvwxyz\n";
  auto display = array<string, 26>{};
  auto max_len = numeric_limits<int>::min();
  for (auto i = 0; i < 26; i++) {
    display[i] = to_string(cnts[i]);
    max_len = max(max_len, (int)display[i].size());
  }
  for (auto i = 0; i < max_len; i++) {
    for (auto j = 0; j < 26; j++) {
      auto &s = display[j];
      if (i < s.size()) {
        cout << s[i];
      } else {
        cout << '$';
      }
    }
    cout << '\n';
  }
}
