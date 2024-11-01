#include <iostream>
using namespace std;
typedef long long ll;
ll T,n,m,k,x,y,z,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>x>>y>>z;
        for(ll i=1;i<=n;i++)
        {
            cin>>mp[i]+1;
            for(ll j=1;j<=m;j++) vis[i][j]=0;
        }
        ll ans=1;
        while(k--)
        {
            vis[x][y]=1;
            ll ax=x+dx[z],ay=y+dy[z];
            if(ax>0&&ax<=n&&ay>0&&ay<=m&&mp[ax][ay]=='.')
            {
                if(!vis[ax][ay]) ans++;
                x=ax,y=ay;
            }
            else z=(z+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
