// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2627
#include <bits/stdc++.h>
using namespace std;
using Ext = string_view;
using Path = string_view;
using MainPart = string_view;
auto split(Path path) -> tuple<MainPart, optional<Ext>> {
    auto pos_of_last_point = path.rfind('.');
    if(pos_of_last_point == Path::npos) {
        return {path, {}};
    } else {
        //assert(pos_of_last_point != path.size() - 1);
        auto main_part = path.substr(0, pos_of_last_point);
        auto ext = path.substr(pos_of_last_point + 1);
        return {main_part, ext};
    }
}

auto rename(string_view path, int cnt) -> string {
    if(cnt == 1) {
        return string(path);
    }
    const auto [main_part, ext] = split(path);
    auto ret = string(main_part);
    ret += "(";
    ret += to_string(cnt);
    ret += ")";
    if(ext.has_value()) {
        ret += ".";
        ret += ext.value();
    }
    return ret;
}

auto main() -> int {
    cin.tie(nullptr) -> sync_with_stdio(false);
    auto n = 0;
    cin >> n;
    auto paths = unordered_set<string>{}; // int表示冲突次数
    for(auto _ = 0; _ < n; _++) {
        auto path = string{};
        cin >> path;
        auto [it, ok] = paths.insert(move(path));
        if(ok) {
            cout << *it << '\n';
            continue;
        }
        const auto& p = *it;
        auto cnt = 2;
        while(true) {
            auto $path = rename(p, cnt);
            auto [it, ok] = paths.insert(move($path));
            if(ok) {
                cout << *it << '\n';
                break;
            }
            cnt++;
        }
    }
}