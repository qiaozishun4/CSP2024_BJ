#include <bits/stdc++.h>
using namespace std;
bool c[4][13];
map < char, int > col{{'D', 0}, {'C', 1}, {'H', 2}, {'S', 3}};
map < char, int > num{{'1', 0}, {'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 10}, {'Q', 11}, {'K', 12}};
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cnt = 0;
    cin >> n;
    string in;
    for (int i = 0;i < n;i++) {
        cin >> in;
        if (c[col[in[0]]][num[in[1]]]) cnt--;
        c[col[in[0]]][num[in[1]]] = 1;
        cnt++;
    }
    cout << 52 - cnt;
    return 0;
}
