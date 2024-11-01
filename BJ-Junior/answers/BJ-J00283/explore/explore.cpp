#include<bits/stdc++.h>
using namespace std;
bool flag[1005][1005];
char ch[1005][1005];
int t,n,m,k,x,y,d;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        memset(flag,0,sizeof(flag));
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>ch[i][j];
        for(int i=1; i<=k; i++)
        {
            int tx,ty,td=(d+1)%4;
            if(d==0) tx=x,ty=y+1;
            else if(d==1) tx=x+1,ty=y;
            else if(d==2) tx=x,ty=y-1;
            else tx=x-1,ty=y;
            if(tx>=1 && tx<=n && ty>=1 && ty<=m && ch[tx][ty]=='.') x=tx,y=ty,ans+=(flag[x][y]==0),flag[x][y]=1;
            else d=td;
        }
        cout<<ans<<endl;
    }
    return 0;
}
