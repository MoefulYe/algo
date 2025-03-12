// url = https://leetcode.cn/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;
using namespace std::ranges;
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    auto max_queue = deque<int>{};
    auto ret = vector<int>{};
    for (const auto i : ranges::iota_view{0, k - 1}) {
      while (!max_queue.empty() && nums[max_queue.back()] <= nums[i]) {
        max_queue.pop_back();
      }
      max_queue.push_back(i);
    }
    for (const auto i : ranges::iota_view{k - 1, (int)nums.size()}) {
      if (!max_queue.empty() && max_queue.front() <= i - k) {
        max_queue.pop_front();
      }
      while (!max_queue.empty() && nums[max_queue.back()] <= nums[i]) {
        max_queue.pop_back();
      }
      max_queue.push_back(i);
      ret.push_back(nums[max_queue.front()]);
    }
    return ret;
  }
};
