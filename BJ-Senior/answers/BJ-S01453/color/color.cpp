#include <bits/stdc++.h>
using namespace std;
int TTTTT,n,a[200005],c[1000005],maxx = -1,mp,sndmaxx,sndmp,ans,sndans;
bool fst,sndfst;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> TTTTT;
    while (TTTTT--)
    {
        cin >> n;
        memset(c,0,sizeof(c));
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }
        fst = 1,sndfst = 1;
        for (int i = 0;i <= 2000;i++)
        {
            if (maxx < c[i])
            {
                maxx = c[i];
                sndmp = mp;
                mp = i;
            }
        }
        ans = 0,sndans = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] == mp)
            {
                if (fst)
                    fst = 0;
                else
                    ans += a[i];
            }
            else if (a[i] == sndmp)
            {
                if (sndfst)
                    sndfst = 1;
                else
                    sndans += a[i];
            }
        }
        cout << max(ans,sndans);
    }
    return 0;
}