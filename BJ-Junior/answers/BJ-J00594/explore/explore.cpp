#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        bool f=1;
        vis[x][y]=1;
        int ans=1;
        for(i=1;i<=k;i++)
        {
            int dy=y,dx=x;
            if(d==0)
            {
                dy++;
            }
            if(d==1)
            {
                dx++;
            }
            if(d==2)
            {
                dy--;
            }
            if(d==3)
            {
                dx--;
            }
            if(dx<=0||dx>n||dy<=0||dy>m||a[dx][dy]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            else
            {
                if(!vis[dx][dy])
                {
                    ans++;
                    vis[dx][dy]=1;
                }
                x=dx;
                y=dy;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
