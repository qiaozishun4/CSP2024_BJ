#include <bits/stdc++.h>
using namespace std;
int t,n,sn[10]={6,2,5,5,4,5,6,3,7,6},ans;
int main ()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int c=ceil(n/7.0);
        if (c>n/2)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i=1;i<=9;i++)
        {
            if (n-sn[i]>(c-1)*7)
            {
                continue;
            }
            if (c-1==0)
            {
                if (sn[i]!=n)
                {
                    continue;
                }
            }
            ans=i;
            n-=sn[i];
            break;
        }
        for (int i=2;i<=c;i++)
        {
            ans*=10;
            for (int j=0;j<=9;j++)
            {
                if (n-sn[j]>(c-1)*7)
                {
                    continue;
                }
                if (c-i==0)
                {
                    if (sn[j]!=n)
                    {
                        continue;
                    }
                }
                ans+=j;
                n-=sn[j];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
