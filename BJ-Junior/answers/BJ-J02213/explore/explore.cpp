#include<bits/stdc++.h>
using namespace std;
char g[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int c,k,x,y,d,t,n,m,ans,i,j;
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++) cin>>g[i][j];
        b[x][y]=1;
        while(k--)
        {
            if(d==0) y++;
            if(d==1) x++;
            if(d==2) y--;
            if(d==3) x--;
            if(g[x][y]=='x'||x<1||y<1||x>n|y>m)
            {
                if(d==0) y--;
                if(d==1) x--;
                if(d==2) y++;
                if(d==3) x++;
                d=(d+1)%4;
                continue;
            }
            if(!b[x][y]) {ans++;b[x][y]=1;}
        }
        printf("%d\n",ans);
        memset(b,0,sizeof(b));
    }
    return 0;
}
