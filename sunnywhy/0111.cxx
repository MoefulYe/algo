
#include <iostream>
#include <string>
auto foo(int n, std::string &output) -> void {
  if (n == 0) {
    output.append("讲你妹的故事啊！快点去睡觉！！！\n");
  } else {
    output.append("从前有座山，山上有座庙\n");
    output.append("庙里有一个老和尚和一个小和尚\n");
    output.append("睡前老和尚给小和尚讲故事：\n");
    foo(n - 1, output);
    output.append("然后老和尚和小和尚就睡觉啦\n");
  }
}

int main(int argc, char *argv[]) {
  auto res = std::string();
  auto n = 0;
  std::cin >> n;
  foo(n, res);
  std::cout << res;
  return 0;
}
