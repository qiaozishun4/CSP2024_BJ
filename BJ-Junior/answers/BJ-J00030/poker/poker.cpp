#include <bits/stdc++.h>
using namespace std;
string s[55], str[55];
char c[] = {'D', 'C', 'H', 'S'};
map<string, int> mp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cur = 0, ans = 52;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) mp[s[i]]++;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            str[++cur] += c[i];
            if (j == 1) str[cur] += 'A';
            if (j >= 2 && j <= 9) str[cur] += char(j + 48);
            if (j == 10) str[cur] += 'T';
            if (j == 11) str[cur] += 'J';
            if (j == 12) str[cur] += 'Q';
            if (j == 13) str[cur] += 'K';
        }
    }
    for (int i = 1; i <= cur; i++)
    {
        if (mp[str[i]]) ans--;
    }
    cout << ans;
    return 0;
}