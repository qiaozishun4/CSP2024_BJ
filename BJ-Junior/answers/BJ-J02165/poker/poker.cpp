#include <bits/stdc++.h>
using namespace std;

bool vis[100];
int work(string s) {
    int ans = 0;
    if (s[0] == 'C')
        ans += 13;
    if (s[0] == 'H')
        ans += 26;
    if (s[0] == 'S')
        ans += 39;
    if (s[1] >= '2' && s[1] <= '9')
        ans += int(s[1] - '0');
    else {
        if (s[1] == 'A')
            ans += 1;
        if (s[1] == 'T')
            ans += 10;
        if (s[1] == 'J')
            ans += 11;
        if (s[1] == 'Q')
            ans += 12;
        if (s[1] == 'K')
            ans += 13;
    }
    return ans;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        vis[work(s)] = 1;
    }
    for (int i = 1; i <= 52; i++)
        if (!vis[i])
            ans++;
    cout << ans << endl;
    return 0;
}