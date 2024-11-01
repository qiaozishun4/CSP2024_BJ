#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int cnt[10][20];

void add(string s)
{
    int x = 0, y = 0;
    if (s[0] == 'D') x = 1;
    if (s[0] == 'C') x = 2;
    if (s[0] == 'H') x = 3;
    if (s[0] == 'S') x = 4;

    if ('0' <= s[1] && s[1] <= '9') y = s[1] - '0';
    if (s[1] == 'A') y = 1;
    if (s[1] == 'T') y = 10;
    if (s[1] == 'J') y = 11;
    if (s[1] == 'Q') y = 12;
    if (s[1] == 'K') y = 13;

    cnt[x][y]++;
}

int check()
{
    int symbol = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            symbol += (cnt[i][j] > 0);
    return symbol;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        add(s);
    }
    cout << 52 - check() << endl;
    return 0;
}

