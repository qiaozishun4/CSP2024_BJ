#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,ex,ey,d,ans;
char a[1111][1111];
bool v[1111][1111];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(int x,int y,int w,int d)
{
    if(w == 0) return ;
    int nx = x+dx[d],ny = y+dy[d];
    if(a[nx][ny] == '.' && nx>0 && ny>0 && nx<=n && ny <=m)
    {
        if(!v[nx][ny])
        {
            ans++;
            v[nx][ny] = 1;
        }
        dfs(nx,ny,w-1,d);
    }
    else
        dfs(x,y,w-1,(d+1)%4);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>ex>>ey>>d;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        ans = 1;
        memset(v,0,sizeof v);
        v[ex][ey] = 1;
        dfs(ex,ey,k,d);
        cout<<ans<<endl;
    }
    return 0;
}
