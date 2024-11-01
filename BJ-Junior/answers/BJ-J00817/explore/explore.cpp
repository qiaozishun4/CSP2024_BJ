#include<iostream>
using namespace std;
void zou()
{
    int n,m,k,x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    int is[1003][1003]={0};
    char g[1003][1003];
    is[x][y]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
        }
    int dx[10]={0,1,0,-1};
    int dy[10]={1,0,-1,0};
    for(int i=1;i<=k;i++)
    {
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&g[nx][ny]=='.')
        {
            x=nx;
            y=ny;
            is[x][y]=1;
        }
        else
        {
            d=(d+1)%4;
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(is[i][j]==1)ans+=1;
    cout<<ans<<endl;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        zou();
    }
    return 0;
}