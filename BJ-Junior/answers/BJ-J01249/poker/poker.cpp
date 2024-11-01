#include<bits/stdc++.h>
using namespace std;

bool cnt[10][20];

int fh(char c)
{
    if(c == 'D') return 1;
    if(c == 'C') return 2;
    if(c == 'H') return 3;
    if(c == 'S') return 4;
    return 0;
}

int fd(char c)
{
    if('0' <= c && c <= '9') return c - '0';
    if(c == 'A') return 1;
    if(c == 'T') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
    return 0;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        cnt[fh(s[0])][fd(s[1])] = 1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!cnt[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}
