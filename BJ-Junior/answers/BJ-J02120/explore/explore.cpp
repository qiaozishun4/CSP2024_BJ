#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool is[1005][1005];
char a[1005][1005];
void dfs(int step)
{
    if(step==0)
    {
        return;
    }
    x+=dx[d];
    y+=dy[d];
    if(a[x][y]=='x' || x==0 || y==0 || x>n || y>m)
    {
        x-=dx[d];
        y-=dy[d];
        d=(d+1)%4;
    }
    else
    {
        if(is[x][y]==0)
        {
            ans++;
        }
        is[x][y]=1;
    }
    dfs(step-1);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                is[i][j]=0;
            }
        }
        is[x][y]=1;
        dfs(k);
        cout<<ans<<endl;
    }
    return 0;
}