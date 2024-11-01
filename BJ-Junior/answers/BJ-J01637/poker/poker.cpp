#include <cstring>
#include <iostream>
using namespace std;

bool f[10][15];

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
        int a, b;
        if (s[0] == 'D') a = 1;
        else if (s[0] == 'C') a = 2;
        else if (s[0] == 'H') a = 3;
        else a = 4;

        if (s[1] == 'A') b = 1;
        else if ('0' <= s[1] && s[1] <= '9' && s.size() == 2) b = s[i] - '0';
        else if (s.size() == 3) b = 10;
        else if (s[1] == 'J') b = 11;
        else if (s[1] == 'Q') b = 12;
        else b = 13;

        f[a][b] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 13; ++j) cnt += !f[i];
    }
    cout << cnt;
    return 0;
}
