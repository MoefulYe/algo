// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2664

#include <bits/stdc++.h>
using namespace std;

struct 拟录取结果 {
    int 数学, 写作, 加分, 学生编号;
    friend auto operator<(const 拟录取结果& lhs, const 拟录取结果& rhs) {
        const auto [数学左, 写作左, 加分左, 编号左] = lhs;
        const auto [数学右, 写作右, 加分右, 编号右] = rhs;
        const auto 总分左 = 数学左 + 写作左 + 加分左;
        const auto 总分右 = 数学右 + 写作右 + 加分右;
        if(总分左 != 总分右) {
            return 总分左 < 总分右;
        } else if (数学左 != 数学右) {
            return 数学左 < 数学右;
        } else if (写作左 != 写作右) {
            return 写作左 < 写作右;
        } else {
            return 编号左 < 编号右;
        }
    }
    static auto gt(const 拟录取结果& lhs, const 拟录取结果& rhs) {
        const auto [数学左, 写作左, 加分左, 编号左] = lhs;
        const auto [数学右, 写作右, 加分右, 编号右] = rhs;
        return 数学左 > 数学右 || 写作左 > 写作右 || 加分左 > 加分右;
    }};

using 拟录取列表 = set<拟录取结果, std::greater<拟录取结果>>;

struct 学生 {
    int 数学, 写作;
    friend auto operator>>(istream& is, 学生& self) -> istream& {
        is >> self.数学 >> self.写作;
        return is;
    }
};

auto is_friend(int no1, int no2) -> bool {
    return true;
}

auto friends_callback(int no, auto callback) { // 对于no编号的学生的每一个好友调用回调函数
    
}

auto back(拟录取列表& 列表) -> 拟录取结果& {
    auto it = 列表.end();
    it--;
    return *it;
}

struct 学校 {
    int 招生人数, 加分, 加分门槛;
    friend auto operator>>(istream& is, 学校& self) -> istream& {
        is >> self.招生人数 >> self.加分 >> self.加分门槛;
        return is; 
    }
    auto 复试(const vector<学生>& 学生列表) -> 拟录取列表 {
        auto 是否加分 = vector<bool>(学生列表.size());
        auto 排名 = vector<int>(学生列表.size());
        // 处理加分
        for(auto i = 0; i < 学生列表.size(); i++) {
            const auto 学生 = 学生列表[i];
            const auto 基础总分 = 学生.数学 + 学生.写作;
            if(基础总分 > this -> 加分门槛) {
                是否加分[i] = true;
            }
            friends_callback(i, [&](int friend) {
                是否加分[friend] = true;
            });
        }
        auto 结果 = 拟录取列表{};
        for(auto i = 0; i < 学生列表.size(); i++) {
            const auto [数学, 写作] = 学生列表[i];
            const auto 加分 = 是否加分[i] ? this -> 加分 : 0;
            const auto 记录 = 拟录取结果 {
                数学, 写作, 加分, 编号
            };
            if(结果.size() >= this -> 招生人数) {
                const auto& last = back(结果);
            } else {
                结果.insert(记录);
            }
        }
    }
};



auto n = 0, m = 0, k = 0;

auto main() -> int {

}