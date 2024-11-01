#include<bits/stdc++.h>

using namespace std;

int num[5][15];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int cnt;
    cin >> cnt;
    for(int i = 1; i <= cnt; i++)
    {
        string s;
        cin >> s;
        int x = 0, y = 0;
        if(s[0] == 'D') x = 1;
        if(s[0] == 'C') x = 2;
        if(s[0] == 'H') x = 3;
        if(s[0] == 'S') x = 4;
        if(s[1] == 'A') y = 1;
        if('2' <= s[1] && s[1] <= '9') y = s[1] - '0';
        if(s[1] == 'T') y = 10;
        if(s[1] == 'J') y = 11;
        if(s[1] == 'Q') y = 12;
        if(s[1] == 'K') y = 13;
        num[x][y]++;
    }
    int ans = 0;
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 13; j++)
            if(num[i][j] == 0) ans++;
    cout << ans << endl;
    return 0;
}
