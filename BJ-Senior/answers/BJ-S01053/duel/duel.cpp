#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000 + 5;
int N, R, C;
set<pair<int, int>> cards;

int main() {
    #ifndef local
    const string fileName = "duel";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> N; N--; cin >> R, cards.insert(make_pair(R, ++C)));
    for (auto i : cards) {
        auto j = cards.lower_bound(make_pair(i.first, 0));
        if (j != cards.begin())
            cards.erase(prev(j));
    }
    cout << cards.size() << '\n';
    return 0;
}
