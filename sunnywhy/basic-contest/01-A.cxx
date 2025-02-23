#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; // 输入的符文组合
  cin >> s;
  vector<string> v; // 存储所有可能的修改结果
  // 遍历每个字符，生成所有可能的修改结果
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    // 向前调整
    char next = (c == '9') ? '0' : c + 1; // 如果是'9'，变为'0'；否则加一
    string t = s;
    t[i] = next;    // 修改当前字符
    v.push_back(t); // 添加到结果集合
    // 向后调整
    char prev = (c == '0') ? '9' : c - 1; // 如果是'0'，变为'9'；否则减一
    t = s;
    t[i] = prev;    // 修改当前字符
    v.push_back(t); // 添加到结果集合
  }
  // 按字典序排序所有修改结果
  sort(v.begin(), v.end());
  // 输出字典序第二小的字符串
  cout << v[1] << endl;
  return 0;
}
