#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
const int N=1e3+10;
ll t,n,m,x,y,k,d;
ll v[N][N],ans;
char a[N][N];
bool nextstep(ll x,ll y,ll d)
{
    ll nx=x+dx[d];
    ll ny=y+dy[d];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
    {
        if(a[nx][ny]=='.')
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        memset(v,0,sizeof(v));
        ans=0;
        while(k)
        {
            v[x][y]=1;
            if(nextstep(x,y,d))
            {
                x+=dx[d];
                y+=dy[d];
            }
            else
            {
                d=(d+1)%4;
            }
            k--;
        }
        v[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ans+=v[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
