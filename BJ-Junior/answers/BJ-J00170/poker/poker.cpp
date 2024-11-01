#include <bits/stdc++.h>
using namespace std;

int d[15], c[15], h[15], s[15];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string st;
        cin >> st;
        if (st[0]=='D')
        {
            char now=st[1];
            if (now=='A') d[1]++;
            else if (now=='T') d[10]++;
            else if (now=='J') d[11]++;
            else if (now=='Q') d[12]++;
            else if (now=='K') d[13]++;
            else d[now-'0']++;
        }
        if (st[0]=='C')
        {
            char now=st[1];
            if (now=='A') c[1]++;
            else if (now=='T') c[10]++;
            else if (now=='J') c[11]++;
            else if (now=='Q') c[12]++;
            else if (now=='K') c[13]++;
            else c[now-'0']++;
        }
        if (st[0]=='H')
        {
            char now=st[1];
            if (now=='A') h[1]++;
            else if (now=='T') h[10]++;
            else if (now=='J') h[11]++;
            else if (now=='Q') h[12]++;
            else if (now=='K') h[13]++;
            else h[now-'0']++;
        }
        if (st[0]=='S')
        {
            char now=st[1];
            if (now=='A') s[1]++;
            else if (now=='T') s[10]++;
            else if (now=='J') s[11]++;
            else if (now=='Q') s[12]++;
            else if (now=='K') s[13]++;
            else s[now-'0']++;
        }
    }
    int ans=0;
    for (int i = 1; i <= 13; i++)
    {
        if (d[i]==0) ans++;
        if (c[i]==0) ans++;
        if (h[i]==0) ans++;
        if (s[i]==0) ans++;
    }
    cout << ans;
    return 0;
}
// please give me an AC!!!!
