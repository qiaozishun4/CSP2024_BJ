#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0},big=1e3;
int t,n,m,k,x,y,d,ans;
char exp[big+2][big+2];
bool vis[big+2][big+2];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        memset(vis,0,sizeof(vis));
        memset(exp,0,sizeof(exp));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<=n+1;i++)
            exp[i][0]=exp[0][i]=exp[n+1][i]=exp[i][n+1]='x';
        for(int i=1;i<=n;i++)
            cin>>exp[i]+1;
        for(int i=1;i<=k;i++)
        {
            if(!vis[x][y])
            {
                vis[x][y]=1;
                ans++;
            }
            if(exp[x+dx[d]][y+dy[d]]=='.')
            {
                x+=dx[d];
                y+=dy[d];
            }
            else
                d=(d+1)%4;
        }
        if(!vis[x][y])
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
