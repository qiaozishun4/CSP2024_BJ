#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int f[1010][1010];
char c[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k;
bool can(int x,int y,int d)
{
    x+=dx[d];
    y+=dy[d];
    if(x<1||x>n||y<1||y>m)return 0;
    if(c[x][y]=='x')return 0;
    return 1;
}
void step(int &x,int &y,int d)
{
    x+=dx[d];
    y+=dy[d];
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(f,0,sizeof(f));
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)cin>>c[i][j];
        }
        while(k--)
        {
            if(f[x][y]==d+1)break;
            f[x][y]=d+1;
            int cnt=0;
            if(!can(x,y,d))
            {
                d++;
                d%=4;
            }
            else step(x,y,d);
            //cout<<x<<' '<<y<<endl;
        }
        f[x][y]=d+1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(f[i][j])ans++;
                //cout<<f[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
}
