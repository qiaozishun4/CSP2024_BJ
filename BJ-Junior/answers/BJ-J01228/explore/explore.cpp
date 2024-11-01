#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool vis[N][N];
char g[N][N];
int n,m,k,x,y,d;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
        while(k--)
        {
            int dx=x,dy=y;
            if(d==0)dy++;
            if(d==1)dx++;
            if(d==2)dy--;
            if(d==3)dx--;
            if(dx<1||dy<1||dx>n||dy>m||g[dx][dy]=='x')d=(d+1)%4;
            else
            {
                if(!vis[dx][dy]) ans++,vis[dx][dy]=1;
                x=dx,y=dy;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
