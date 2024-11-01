#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t;
ll add(ll d)
{
    d=(d+1)%4;
    return d;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        char mp[1010][1010];
        cin>>n>>m>>k;
        ll x,y,d;
        bool vis[1010][1010];
        cin>>x>>y>>d;
        memset(vis,0,sizeof(vis));
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        vis[x][y]=1;
        while(k--)
        {
            if(d==0)
            {
                ll xp=x+1;
                if(xp<=0||xp>m||mp[xp][y]=='x')
                {
                    d=add(d);
                }
                else
                {
                    x=xp;
                    vis[y][x]=1;
                }
                continue;
            }
            if(d==1)
            {
                ll yp=y-1;
                if(yp<=0||yp>n||mp[x][yp]=='x')
                {
                    d=add(d);
                }
                else
                {
                    y=yp;
                    vis[y][x]=1;
                }
                continue;
            }
            if(d==2)
            {
                ll xp=x-1;
                if(xp<=0||xp>m||mp[xp][y]=='x')
                {
                    d=add(d);
                }
                else
                {
                    x=xp;
                    vis[y][x]=1;
                }
                continue;
            }
            if(d==3)
            {
                ll yp=y+1;
                if(yp<=0||yp>n||mp[x][yp]=='x')
                {
                    d=add(d);
                }
                else
                {
                    y=yp;
                    vis[y][x]=1;
                }
                continue;
            }
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if(vis[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
