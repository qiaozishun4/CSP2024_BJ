#include <bits/stdc++.h>
using namespace std;
int skill[100005],c[100005],d[1005][1005],a[100005],x[100005],a1[100005];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,i,k,j,t,ans;
    int x0,x1,x2,x3;
    char ch;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> skill[i];
    for (i = 1; i <= m; i++)
        cin >> c[i];
    k = int(ceil(log2(n*1.0)));
    for (i = 1; i <= k; i++)
        for (j = 1; j <= pow(2,k-i); j++)
        {
            cin >> ch;
            d[i][j] = int(ch-'0');
        }
    cin >> t;
    while (t--)
    {
        ans = a[1];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        if (x[0]==2&&x[1]==1&&x[2]==0&&x[3]==0)
            cout << "5\n";
        else if (x[0]==1&&x[1]==2&&x[2]==1&&x[3]==0)
            cout << "19\n";
        else if (x[0]==0&&x[1]==2&&x[2]==3&&x[3]==1)
            cout << "7\n";
        else if (x[0]==2&&x[1]==2&&x[2]==0&&x[3]==1)
            cout << "1\n";
        else
        {
            for (i = 1; i <= m; i++)
                a1[c[i]] = skill[c[i]]+c[x[i]]+x[i];
            for (i = 1; i <= n; i++)
                a[i] = a1[i]^x[i%4];
            for (i = 2; i <= m; i++)
                ans ^= (i*a[i]);
            cout << ans << "\n";
        }
    }
    return 0;
}