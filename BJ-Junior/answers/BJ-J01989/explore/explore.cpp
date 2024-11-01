#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;
char mp[N][N];
int n,m,k;
bool vis[N][N];
void move(int &x,int &y,int d)
{
    if(d==0)y++;
    if(d==1)x++;
    if(d==2)y--;
    if(d==3)x--;
}
bool check(int x,int y)
{
    if(x<=n&&y<=m&&mp[x][y]=='.')return 1;
    return 0;
}
void turn(int &d)
{
    d=(d+1)%4;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int x,y,d;
        memset(mp,0,sizeof mp);
        memset(vis,0,sizeof vis);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;++i)
        {
            scanf("%s",mp[i]+1);
        }
        vis[x][y]=1;
        for(int i=1;i<=k;++i)
        {
            int tx=x,ty=y;
            move(tx,ty,d);
            if(check(tx,ty))
            {
                x=tx,y=ty;
                vis[tx][ty]=1;
            }
            else
            {
                turn(d);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(vis[i][j])cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
