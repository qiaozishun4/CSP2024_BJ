#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[1005] , d[1005] , h[1005] , s[1005] , n;
signed main()
{
    freopen("poker.in" , "r" , stdin);
    freopen("poker.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char x , y;
        cin >> x >> y;
        if(x == 'C') c[y]++;
        if(x == 'D') d[y]++;
        if(x == 'H') h[y]++;
        if(x == 'S') s[y]++;
    }
    int cnt = 52;
    for(char i = '2'; i <= '9'; i++)
    {
        if(c[i]) cnt--;
        if(d[i]) cnt--;
        if(h[i]) cnt--;
        if(s[i]) cnt--;
    }
    if(c['A']) cnt--;
    if(d['A']) cnt--;
    if(h['A']) cnt--;
    if(s['A']) cnt--;


    if(c['T']) cnt--;
    if(d['T']) cnt--;
    if(h['T']) cnt--;
    if(s['T']) cnt--;


    if(c['J']) cnt--;
    if(d['J']) cnt--;
    if(h['J']) cnt--;
    if(s['J']) cnt--;


    if(c['Q']) cnt--;
    if(d['Q']) cnt--;
    if(h['Q']) cnt--;
    if(s['Q']) cnt--;

    if(c['K']) cnt--;
    if(d['K']) cnt--;
    if(h['K']) cnt--;
    if(s['K']) cnt--;
    cout << cnt << endl;
    return 0;
}
