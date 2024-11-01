#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
#define endl '\n'
char map1[1005][1005];
ll shi[1005][1005];
ll t;
ll n,m,k;
ll x,y,d;
ll ans;
void go(ll x,ll y,ll d,ll now)
{
    if(shi[x][y]==0)
    {
        ++ans;
        shi[x][y]=1;
    }
    if(now==k)return;
    if(d==0)
    {
        if(map1[x][y+1]=='.'&&x<=n&&x>=1&&y+1<=m&&y+1>=1)
        {
            go(x,y+1,d,++now);
        }
        else
        {
            go(x,y,(d+1)%4,++now);
        }
    }
    else if(d==1)
    {
        if(map1[x+1][y]=='.'&&x+1<=n&&x+1>=1&&y<=m&&y>=1)
        {
            go(x+1,y,d,++now);
        }
        else
        {
            go(x,y,(d+1)%4,++now);
        }
    }
    else if(d==2)
    {
        if(map1[x][y-1]=='.'&&x<=n&&x>=1&&y-1<=m&&y-1>=1)
        {
            go(x,y-1,d,++now);
        }
        else
        {
            go(x,y,(d+1)%4,++now);
        }
    }
    else if(d==3)
    {
        if(map1[x-1][y]=='.'&&x-1<=n&&x-1>=1&&y<=m&&y>=1)
        {
            go(x-1,y,d,++now);
        }
        else
        {
            go(x,y,(d+1)%4,++now);
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    string a;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(ll j=1;j<=n;j++)
        {
            cin>>a;
            for(ll k=0;k<m;k++)
            {
                map1[j][k+1]=a[k];
                shi[j][k+1]=0;
            }
        }
        shi[x][y]=1;
        ans=1;
        go(x,y,d,0);
        cout<<ans<<endl;
    }
    return 0;
}
