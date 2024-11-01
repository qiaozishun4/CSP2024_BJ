#include<bits/stdc++.h>
using namespace std;
#define LL long long
char ch[1005][1005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //open that


    //start the freopen when you end the match
    //need to know : unsigned

    LL t,i,j,n,m,k,x,y,d,ans;
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        memset(vis,0,sizeof(vis));
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
        vis[x][y]=1;
        ans++;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>ch[i][j];
        while(k--)
        {
            //printf("x:%lld y:%lld d:%lld\n",x,y,d);
            int tx=x+dx[d],ty=y+dy[d];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&ch[tx][ty]=='.')
            {
                x=tx,y=ty;
            }
            else d=(d+1)%4;
            if(!vis[x][y])
            {
                //printf("pluson x:%lld y:%lld d:%lld\n",x,y,d);
                vis[x][y]=1;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
