#include <iostream>
#include <cstdio>
using namespace std;

int n, a[10][20];
string s;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int x, y;
        if (s[0] == 'D') x = 1;
        else if (s[0] == 'C') x = 2;
        else if (s[0] == 'H') x = 3;
        else x = 4;
        if (s[1] == 'A') y = 1;
        else if (s[1] == 'T') y = 10;
        else if (s[1] == 'J') y = 11;
        else if (s[1] == 'Q') y = 12;
        else if (s[1] == 'K') y = 13;
        else y = s[1] - '0';
        a[x][y] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            if (!a[i][j]) cnt++;
    cout << cnt << "\n";
    return 0;
}