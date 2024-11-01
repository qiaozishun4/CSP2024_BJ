#include <bits/stdc++.h>
using namespace std;

int a[100][100];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        int hang, lie;
        if (s[0] == 'D') hang = 1;
        else if (s[0] == 'C') hang = 2;
        else if (s[0] == 'H') hang = 3;
        else hang = 4;
        if (s[1] == 'J') lie = 11;
        else if (s[1] == 'Q') lie = 12;
        else if (s[1] == 'K') lie = 13;
        else if (s[1] == 'T') lie = 10;
        else if (s[1] == 'A') lie = 1;
        else lie = s[1] - '0';
        a[hang][lie] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 13; ++j)
        {
            ans += 1 - a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
