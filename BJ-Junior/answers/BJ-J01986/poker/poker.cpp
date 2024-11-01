#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200;
int n, ta[N], ans;
string s[N];
bool tong[N][N];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ta['A'] = 1;
    ta['T'] = 10;
    ta['J'] = 11;
    ta['Q'] = 12;
    ta['K'] = 13;
    for (int i = '2'; i <= '9'; ++i) ta[i] = i - '0';
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) tong[s[i][0]][ta[s[i][1]]] = true;
    for (int i = 1; i <= 13; ++i) {
        if (!tong['D'][i]) ++ans;
        if (!tong['C'][i]) ++ans;
        if (!tong['S'][i]) ++ans;
        if (!tong['H'][i]) ++ans;
    }
    cout << ans;
    return 0;
}