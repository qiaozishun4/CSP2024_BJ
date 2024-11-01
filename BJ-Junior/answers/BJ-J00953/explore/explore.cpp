#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n,m,k,x,y,d,ans=0;
ll xf[4]={0,1,0,-1},yf[4]={1,0,-1,0};
bool b[1005][1005]={};
char a[1005][1005];

void dfs(ll xx,ll yy,ll dd,ll kk)
{
 //   cout<<xx<<" "<<yy<<" "<<dd<<" "<<kk<<"\n";
    if(kk==k)return ;
    else
    {
        ll x1=xx+xf[dd],y1=yy+yf[dd];
        if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&a[x1][y1]=='.')
        {
            if(b[x1][y1]==0)
            {
                b[x1][y1]=1;
                ans++;
            }
            dfs(x1,y1,dd,kk+1);
        }
        else dfs(xx,yy,(dd+1)%4,kk+1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(b,0,sizeof(b));
        b[x][y]=1;ans=1;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)cin>>a[i][j];
        dfs(x,y,d,0);
        cout<<ans<<"\n";
    }
    return 0;
}
