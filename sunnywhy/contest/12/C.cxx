// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2481&contestSubTab=problem&pid=C

#include <bits/stdc++.h>
using namespace std;

struct SOrder {
    int price, id, num;
    friend auto operator<(const SOrder& lhs, const SOrder& rhs) {
        if(lhs.price != rhs.price) {
            return lhs.price > rhs.price;
        } else {
            return lhs.id > rhs.id;
        }
    }
};

struct BOrder {
    int price, id, num;
    friend auto operator<(const BOrder& lhs, const BOrder& rhs) {
        if(lhs.price != rhs.price) {
            return lhs.price < rhs.price;
        } else {
            return lhs.id > rhs.id;
        }
    }
};

auto main() -> int {
    auto sorders = priority_queue<SOrder>{};
    auto borders = priority_queue<BOrder>{};
    auto n = 0;
    cin >> n;
    auto type = string("");
    auto price = 0, num = 0;
    for(auto i = 0; i < n; i++) {
        cin >> type;
        cin >> price >> num;
        assert(type == "B" || type == "S");
        if(type == "B") {
            auto border = BOrder {
                price,
                i,
                num
            };
            while(!sorders.empty() && border.price >= sorders.top().price && border.num > 0) {
                auto sorder = sorders.top();
                sorders.pop();
                auto num = min(border.num, sorder.num);
                sorder.num -= num;
                border.num -= num;
                if(sorder.num != 0) {
                    sorders.push(sorder);
                }
            }
            if(border.num != 0) {
                borders.push(border);
            }
        } else { // 卖
            auto sorder = SOrder {
                price,
                i,
                num
            };
            while(!borders.empty() && sorder.price <= borders.top().price && sorder.num > 0) {
                auto border = borders.top();
                borders.pop();
                auto num = min(border.num, sorder.num);
                sorder.num -= num;
                border.num -= num;
                if(border.num != 0) {
                    borders.push(border);
                }
            }
            if(sorder.num != 0) {
                sorders.push(sorder);
            }
        }
    }
    cout << borders.size() << "\n";
    while(!borders.empty()) {
        auto [price, _, num] = borders.top();
        borders.pop();
        cout << "B " << price << " " << num << "\n";
    }
    cout << sorders.size() << "\n";
    while(!sorders.empty()) {
        auto [price, _, num] = sorders.top();
        sorders.pop();
        cout << "S " << price << " " << num << "\n";
    }
}