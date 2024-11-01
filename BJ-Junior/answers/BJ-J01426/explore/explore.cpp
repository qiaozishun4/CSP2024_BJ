#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
typedef long long ll;
ll t;
ll n,m,k;
char c[N][N];
bool f[N][N];
void move(ll &x,ll &y,ll &d)
{
    int tx=x,ty=y;
    if(d==0) ty++;
    if(d==1) tx++;
    if(d==2) ty--;
    if(d==3) tx--;
    if(tx<1 || ty<1 || tx>n || ty>m || c[tx][ty]=='x')
    {
        d=(d+1)%4;
        return ;
    }
    x=tx,y=ty;
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        ll x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                cin>>c[i][j];
        f[x][y]=true;
        while(k--)
        {
            move(x,y,d);
            f[x][y]=true;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
            {
                if(f[i][j])
                {
                    ans++;
                    f[i][j]=false;
                }
            }
        cout<<ans<<"\n";
    }
    return 0;
}
