#include <bits/stdc++.h>
using namespace std;

// 思路：模拟，用 unordered_set 去重。
// 全部样例检查完毕。预估 100pts。

string card;
unordered_set<string> cardSet;
int N;

int main() {
    #ifndef local
    const string fileName = "poker";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> N; N--; cin >> card, cardSet.insert(card));
    cout << 52 - cardSet.size() << '\n';
    return 0;
}