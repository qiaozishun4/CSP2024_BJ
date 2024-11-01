#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,k;
int xs,ys,ds;
char a[1010][1010];
bool vs[1010][1010];
int dx[5]{0,1,0,-1};
int dy[5]{1,0,-1,0};
bool in(int x,int y)
{
    return x>0 && x<=n && y>0 && y<=m;
}
void dfs(int x,int y,int dr,int u)
{
    if(u>k) return ;
    vs[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int pd=(i+dr)%4;
        int px=x+dx[pd];
        int py=y+dy[pd];
        if(in(px,py) && a[px][py]=='.')
        {
            dfs(px,py,pd,u+1);
            break;
        }
        else u++;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k >> xs >> ys >> ds;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin >> a[i][j];
        memset(vs,0,sizeof(vs));
        dfs(xs,ys,ds,0);
        int cs=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(vs[i][j])
                    cs++;
        cout << cs << endl;
    }
    return 0;
}