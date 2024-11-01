#include<bits/stdc++.h>
using namespace std;
#define N 1010
char a[N][N];
int n,m,v[N][N];
int dis[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
int in(int x,int y) { return x>0 && x<=n && y>0 && y<=m; };
void print()
{
    cout<<"print::\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k,x,y,d,ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>a[i][j],v[i][j]=0;
        v[x][y]=1;
        while(k>0)
        {
            int nx=x+dis[d][0],ny=y+dis[d][1];
            if(!in(nx,ny) || a[nx][ny]=='x') d=(d+1)%4;
            else x=nx,y=ny,v[x][y]=1;
            k--;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) ans+=v[i][j];
        //print();
        cout<<ans<<endl;
    }
    return 0;
}
