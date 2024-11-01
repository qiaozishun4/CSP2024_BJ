#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const int N=1e3+23;
int n,m,k;
int a[N][N],v[N][N];
inline void _main()
{
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    char c;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf(" %c",&c),a[i][j]=(c=='x');
    memset(v,0,sizeof v);
    v[x][y]=1;
    while (k--)
    {
        int xx,yy;
        if (d==0) xx=x,yy=y+1;
        if (d==1) xx=x+1,yy=y;
        if (d==2) xx=x,yy=y-1;
        if (d==3) xx=x-1,yy=y;
        if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&!a[xx][yy]) v[x=xx][y=yy]=1;
        else d=(d+1)%4;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            ans+=v[i][j];
    cout<<ans<<endl;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    for (cin>>t;t;t--) _main();

    return 0;
}
//orz to nzhtl1477
//rp<<=114514
