#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1001][1001];
bool vis[1001][1001];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n,m,k,x,y,d,ans;
    cin>>T;
    while(T--)
    {
        ans=1;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1 || nx>n || ny<1 || ny>m || mp[nx][ny]=='x')
            {
                d=(d+1)%4;
                //cerr<<"err:"<<d<<endl;
            }
            else
            {
                x=x+dx[d],y=y+dy[d];
                if(vis[x][y]==0)
                {
                    ans++;
                    vis[x][y]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    cout<<flush;
    return 0;
}
