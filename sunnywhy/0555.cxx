#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool notAllow[10] = {false}; // 是否不允许出现

char getMinAllowFrom(int start) { // 返回 >= start 的最小允许的数字
  for (int i = start; i <= 9; i++) {
    if (!notAllow[i]) {
      return '0' + i;
    }
  }
}

int findFirstNotAllowPos(string s) { // 返回从左到右碰到的第一个不允许的位置
  for (int i = 0; i < s.length(); i++) {
    if (notAllow[s[i] - '0']) {
      return i;
    }
  }
}

int main() {
  string s;
  int k, x;
  cin >> s >> k;
  for (int i = 0; i < k; i++) {
    cin >> x;
    notAllow[x] = true; // 设置不允许数字
  }
  char minAllowFrom0 = getMinAllowFrom(0); // >= 0 的最小允许数字
  char minAllowFrom1 = getMinAllowFrom(1); // >= 1 的最小允许数字
  int firstNotAllowPos =
      findFirstNotAllowPos(s); // 从左到右碰到的第一个不允许的位置
  string rightString = string(
      s.substr(firstNotAllowPos + 1).length(),
      minAllowFrom0); // 从第一个不允许的位置的下一个位置开始，全部设置为从0开始的最小允许数字
  bool up = false;    // 是否进位
  while (firstNotAllowPos >=
         0) { // 从第一个不允许的位置开始不断往左扫描，每次处理一个位置
    if (up) { // 如果需要进位
      s[firstNotAllowPos]++; // 让当前位置加1，注意可以分析出来这里一定不会再次发生进位
      up = false;            // 设置为不进位
    }
    while (notAllow[s[firstNotAllowPos] -
                    '0']) { // 不断让当前位置的数字加1，直到碰到允许的数字
      if (s[firstNotAllowPos] == '9') { // 如果当前是9，那么需要进位
        up = true;                      // 设置为需要进位
        s[firstNotAllowPos] =
            minAllowFrom0; // 9进位后是0，直接设置成从0开始的最小允许数字
      } else {
        s[firstNotAllowPos]++; // 不需要进位时当前位置直接加1
      }
    }
    rightString = to_string(s[firstNotAllowPos] - '0') +
                  rightString; // 把当前位置的数字拼接在 rightString最前面
    firstNotAllowPos--; // 处理左侧下一个的位置
  }
  if (up) { // 如果最左侧需要进位，那么补一个从1开始的最小允许数字
    rightString = to_string(minAllowFrom1 - '0') + rightString;
  }
  cout << rightString; // 输出结果
  return 0;
}
