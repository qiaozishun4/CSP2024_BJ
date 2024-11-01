#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n,m,k,x,y,d,ans;
char a[1010][1010];
bool vis[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while (t--)
    {
        for (ll i=0;i<1010;i++)
        {
            for (ll j=0;j<1010;j++)
            {
                vis[i][j]=0;
            }
        }
        ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for (ll i=1;i<=n;i++)
        {
            for (ll j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        while (k--)
        {
            ll tmpx,tmpy;
            if (d==0)
            {
                tmpx=x,tmpy=y+1;
            }
            else if (d==1)
            {
                tmpx=x+1,tmpy=y;
            }
            else if (d==2)
            {
                tmpx=x,tmpy=y-1;
            }
            else if (d==3)
            {
                tmpx=x-1,tmpy=y;
            }
            if (tmpx>=1 && tmpx<=n && tmpy>=1 && tmpy<=m)
            {
                if (a[tmpx][tmpy]=='.')
                {
                    x=tmpx;
                    y=tmpy;
                    if (!vis[tmpx][tmpy])
                    {
                        ans++;
                        vis[tmpx][tmpy]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
