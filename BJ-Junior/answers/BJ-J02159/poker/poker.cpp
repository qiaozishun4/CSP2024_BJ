#include <bits/stdc++.h>
using namespace std;
int n,sum;
int dd,cc,hh,ss;
string a;
string d[70],c[70],h[70],s[70];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a;
        if(a[0] == 'H')
        {
            hh++;
            h[hh] = a;
        }
        else if(a[0] == 'C')
        {
            cc++;
            c[cc] = a;
        }
        else if(a[0] == 'D')
        {
            dd++;
            d[dd] = a;
        }
        else
        {
            ss++;
            s[ss] = a;
        }
    }
    sort(h + 1,h + hh + 1);
    sort(c + 1,c + cc + 1);
    sort(d + 1,d + dd + 1);
    sort(s + 1,s + ss + 1);
    int hhh = hh,ccc = cc,ddd = dd,sss = ss;
    for(int i = 2;i <= hh;i++)
    {
        if(h[i] == h[i-1])
        {
            hhh--;
        }
    }
    for(int i = 2;i <= cc;i++)
    {
        if(c[i] == c[i-1])
        {
            ccc--;
        }
    }
    for(int i = 2;i <= dd;i++)
    {
        if(d[i] == d[i-1])
        {
            ddd--;
        }
    }
    for(int i = 2;i <= ss;i++)
    {
        if(s[i] == s[i-1])
        {
            sss--;
        }
    }
    sum = hhh + ccc + ddd + sss;
    cout << 52 - sum;
    return 0;
}
