// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2663

#include <bits/stdc++.h>
using namespace std;
template<typename Comp = std::greater<int>>
using Heap = priority_queue<int, vector<int>, Comp>;

auto input_heap(int num, int sel) -> Heap<> {
    auto ret = Heap<>{};
    for(auto _ = 0; _ < num; _ ++) {
        auto item = 0;
        cin >> item;
        if(ret.size() < sel) {
            ret.push(item);
        } else if (ret.top() >= item) {
            continue;
        } else { // as.top < a
            ret.pop();
            ret.push(item);
        }
    }
    return ret;
}

auto heap_sum(Heap<>& heap) -> uint64_t {
    auto sum = 0uz;
    while(!heap.empty()) {
        auto top = heap.top();
        heap.pop();
        sum = sum + top;
    }
    return sum;
}

auto main() -> int {
    auto a_sel = 0, b_sel = 0, c_sel = 0, a_num = 0, b_num = 0, c_num = 0, x_num = 0;
    cin >> a_sel >> b_sel >> c_sel >> a_num >> b_num >> c_num >> x_num;
    auto as = input_heap(a_num, a_sel);
    auto bs = input_heap(b_num, b_sel);
    auto cs = input_heap(c_num, c_sel);
    for_each_n(istream_iterator<int>(cin), x_num, [&](int x) {
        auto a = as.top();
        auto b = bs.top();
        auto c = cs.top();
        auto min = std::min({ a,b,c });
        if(min >= x) {
            return;
        } else if (min == a) {
            as.pop();
            as.push(x);
        } else if (min == b) {
            bs.pop();
            bs.push(x);
        } else { // min == c
            cs.pop();
            cs.push(x);
        }
    });
    auto a_sum = heap_sum(as);
    auto b_sum = heap_sum(bs);
    auto c_sum = heap_sum(cs);
    auto sum = a_sum + b_sum + c_sum;
    cout << sum;
}