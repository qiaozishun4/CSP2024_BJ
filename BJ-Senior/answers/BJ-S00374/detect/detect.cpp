#include <bits/stdc++.h>
using namesapce  std;
int main()
{
    freopen("detect","r",stdin);
    freopen("detect","w",stdout);
    int T;
    for(int i = 1;i <= T;i++)
    {
        int n,m,L,V;
        cin >>n>>m>>L>>V;
        int d[n+5], v[n+5] ,a[n+5], p[m+5];
        for(int j = 1;j <= n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j = 1;j <= m;j++)
        {
            cin>>p[j];
        }
        if(m % 2 == 0)
        {
            cout << n/2 << " ";
        }
        else
        {
            cout << (n+1)/2 << " ";
        }
        if(m % 2 == 0)
        {
            cout << m/2 << endl;
        }
        else
        {
            cout << (m+1)/2 << endl;
        }
    }
    return 0;
}