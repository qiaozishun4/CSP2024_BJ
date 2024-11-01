#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int f[100];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        int cnt = 0;
        if(s[0] == 'D') cnt = 13;
        if(s[0] == 'H') cnt = 26;
        if(s[0] == 'S') cnt = 39;
        if(s[1] == 'A') cnt++;
        if(s[1] == 'T') cnt+=10;
        if(s[1] == 'J') cnt+=11;
        if(s[1] == 'Q') cnt+=12;
        if(s[1] == 'K') cnt+=13;
        if(s[1] >= '2' && s[1] <= '9') cnt+=(s[1] - '0');
        f[cnt] = true;
    }
    int ans = 0;
    for(int i = 1;i <= 52;i++)
    {
        if(!f[i]) ans++;
    }
    cout << ans;
    return 0;
}
