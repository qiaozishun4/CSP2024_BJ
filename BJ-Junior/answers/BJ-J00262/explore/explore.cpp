#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll t,n,m,k,x,y,d,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[1005][1005];
bool mark[1005][1005];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        ll ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        mark[x][y]=1;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                cin>>a[i][j];
        while(k--)
        {
            ll xt=x+dir[d][0],yt=y+dir[d][1];
            if(xt>=1&&xt<=n&&yt>=1&&yt<=m&&a[xt][yt]=='.')
            {
                x=xt,y=yt;
                mark[xt][yt]=1;
            }
            else
                d=(d+1)%4;
        }
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                if(mark[i][j])
                    ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
