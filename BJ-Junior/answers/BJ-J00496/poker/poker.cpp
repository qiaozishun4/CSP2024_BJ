#include <bits/stdc++.h>
using namespace std;

int n;
bool flag[5][15];

int a_to_num(char c)
{
    if (c == 'D') return 1;
    if (c == 'C') return 2;
    if (c == 'H') return 3;
    return 4;
}

int b_to_num(char c)
{
    if (c == 'A') return 1;
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return c - '0';
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    while (n--)
    {
        char a, b;
        cin >> a >> b;
        flag[a_to_num(a)][b_to_num(b)] = true;
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            if (!flag[i][j]) ans++;
    cout << ans << endl;
    return 0;
}