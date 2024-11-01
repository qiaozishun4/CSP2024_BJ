#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define r register
using namespace std;

typedef long long l;
char op[] = {'S', 'H', 'C', 'D'}, num[] = {0, 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
set<pair<char, char>> s;

inline l read() {
    r l x(0);
    r char ch;
    for (; !isdigit(ch); ch = getchar()) ;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x;
}

inline char readchar() {
    r char ch;
    for (; ch < 48; ch = getchar()) ;
    return ch;
}

inline void print(r l x) {
    if (!x) putchar(48);
    r char out[19];
    r l len(0);
    while (x != 0) {
        out[++len] = x % 10 + 48;
        x /= 10;
    }
    while (len) putchar(out[len--]);
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    r l n(read()), ans(52);
    while (n--) {
        char x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }
    for (r l i(0); i < 4; ++i) {
        for (r l j(1); j < 14; ++j) {
            if (s.count(make_pair(op[i], num[j]))) {
                --ans;
            }
        }
    }
    print(ans);
}
