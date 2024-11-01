#include <iostream>
#include <cstdio>
using namespace std;
bool vis[110][50];
char p[9] = {'D', 'C', 'H', 'S'};
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c, t; int num;
        cin >> c >> t;
        if (t == 'A') num = 1;
        else if (t == 'T') num = 10;
        else if (t == 'J') num = 11;
        else if (t == 'Q') num = 12;
        else if (t == 'K') num = 13;
        else num = t - '0';
        vis[c][num] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            if (!vis[p[i]][j]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
