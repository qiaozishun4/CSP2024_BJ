#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
long long ans;
int x,y,d,vis[1005][1005];
char s[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
                vis[i][j]=1;
            }
        }
        vis[x][y]=0;
        for(int i=0;i<k;i++)
        {
            int x2=x,y2=y;
            if(d==0)
                y2+=1;
            else if(d==1)
                x2+=1;
            else if(d==2)
                y2-=1;
            else
                x2-=1;
            if(x2>=1&&y2>=1&&x2<=n&&y2<=m&&s[x2][y2]=='.')
                x=x2,y=y2,ans+=vis[x2][y2],vis[x2][y2]=0;
            else
                d=(d+1)%4;
            //cout<<x<<y<<d<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
