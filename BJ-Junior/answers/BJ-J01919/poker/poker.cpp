#include <bits/stdc++.h>
using namespace std;

bool f[5][15];
int n, cnt;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        int x, y;
        if(s[0] == 'D')
            x = 1;
        else if(s[0] == 'C')
            x = 2;
        else if(s[0] == 'H')
            x = 3;
        else
            x = 4;
        if(s[1] == 'J')
            y = 11;
        else if(s[1] == 'Q')
            y = 12;
        else if(s[1] == 'K')
            y = 13;
        else if(s[1] == 'T')
            y = 10;
        else if(s[1] == 'A')
            y = 1;
        else
            y = s[1] - '0';
        f[x][y] = true;
    }
    for(int i = 1; i <= 4; ++i)
    {
        for(int j = 1; j <= 13; ++j)
            if(!f[i][j]) ++cnt;
    }
    printf("%d", cnt);
    return 0;
}
