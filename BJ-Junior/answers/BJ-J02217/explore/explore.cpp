#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,ans;
string s[1010];
int v[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        ans=0;
        ans++;
        memset(v,0,sizeof(v));
        v[x][y]=1;
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=1;i<=k;i++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&s[nx][ny-1]=='.')
            {
                x=nx,y=ny;
                if(!v[nx][ny])
                    ans++;
                v[nx][ny]=1;
            }
            else
                d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
