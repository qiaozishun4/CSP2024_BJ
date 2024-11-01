#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=0x3f3f3f3f;
char a[N][N];
bool vis[N][N];
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
int ans;
int T,x,y,k,n,m,d;
struct nod
{
    int x,y,d,k;
};
void init()
{
    memset(vis,false,sizeof vis);
    ans=0;
}
void bfs()
{
    queue<nod>q;
    q.push(nod{x,y,d,k});
    vis[x][y]=true;
    ans++;
    while(!q.empty())
    {
        nod u=q.front();
        q.pop();
        if(u.k==0)
        {
            continue;
        }
        int tx=u.x+dx[u.d];
        int ty=u.y+dy[u.d];
        if(a[tx][ty]!='x'&&tx>=1&&ty>=1&&tx<=n&&ty<=m)
        {
            u.k-=1;
            q.push(nod{tx,ty,u.d,u.k});

            if(!vis[tx][ty])
            {
                ans++;
            }
            vis[tx][ty]=true;
        }
        else
        {
            u.d=(u.d+1)%4;
            u.k-=1;
            if(u.k==0)
            {
                continue;
            }
            q.push(u);
        }

    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>T;
    while(T--)
    {
        init();
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
            }
        }
        bfs();
        cout<<ans<<'\n';
    }
    return 0;
}
