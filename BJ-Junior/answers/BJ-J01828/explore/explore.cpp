#include<bits/stdc++.h>
using namespace std;
char maps[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>maps[i][j];
        }
        vis[x][y]=true;
        while(k--)
        {
            int X=x,Y=y;
            if(d==0) Y++;
            if(d==1) X++;
            if(d==2) Y--;
            if(d==3) X--;
            if(X<1||X>n||Y<1||Y>m||maps[X][Y]=='x') d=(d+1)%4;
            else x=X,y=Y;
            vis[x][y]=true;
            //cout<<d<<" "<<X<<" "<<Y<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) ans++;
                vis[i][j]=false;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
