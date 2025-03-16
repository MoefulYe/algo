// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2665&problemSubTab=solution&problemSubId=1857572335
#include <iostream>

#include <string>

using namespace std;


int main() {

    string s;

    long long k;

    cin >> s >> k;

    long long sum = 0; // 累计不可扩展字符的总长度

    

    for (char c : s) {

        // 确定当前字符的扩展倍数（不可扩展字符m=1）

        long long m;

        if (c == 'F') m = 2;

        else if (c == 'I') m = 3;

        else if (c == 'R') m = 4;

        else if (c == 'E') m = 5;

        else m = 1;

        

        if (m > 1) {

            // 可扩展字符的起始位置为sum+1，若K在此范围内则直接命中

            if (sum < k) {

                cout << c << endl;

                return 0;

            }

        } else {

            // 不可扩展字符累加长度后判断

            sum += 1;

            if (sum >= k) {

                cout << c << endl;

                return 0;

            }

        }

    }

    return 0;

}