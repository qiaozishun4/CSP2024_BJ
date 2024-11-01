#include <bits/stdc++.h>
using namespace std;
bool b[57];

int n;
int cal(string s)
{
    int ans = 0;

    if (s[1] == 'A') ans += 1;
    if (s[1] == 'T') ans += 10;
    if (s[1] == 'J') ans += 11;
    if (s[1] == 'Q') ans += 12;
    if (s[1] == 'K') ans += 13;
    if (s[1] <= '9' && s[1] >= '0') ans += s[1] - '0';
    ans = (ans - 1) * 4;
    if (s[0] == 'D') ans += 0;
    if (s[0] == 'C') ans += 1;
    if (s[0] == 'H') ans += 2;
    if (s[0] == 'S') ans += 3;
    ans ++;
    return ans;

}
int main()
{
    string s[105];
    memset(b, 0, sizeof b);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        b[cal(s[i])] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= 52; i++)
        if (b[i])
            cnt ++;

    cout << 52-cnt << endl;
    return 0;
}
