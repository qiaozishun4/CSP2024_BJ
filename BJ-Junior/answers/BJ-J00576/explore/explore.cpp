#include<bits/stdc++.h>
using namespace std;
const int maxn=1000,maxm=1000;
char mp[maxn+5][maxm+5];
bool vis[maxn+5][maxm+5];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long T;
    long long n,m,k,xj,yj,fx;
    cin>>T;
    while(T--)
    {
        memset(mp,' ',sizeof(mp));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>xj>>yj>>fx;
        for(long long i=1;i<=n;i++)
        {

            for(long long j=1;j<=m;j++)
            {
                cin>>mp[i][j];

            }
        }
        long long ans=0;
        vis[xj][yj]=1;
        for(long long i=1;i<=k;i++)
        {

            if(fx==0)
            {

                if(mp[xj][yj+1]!='x'&&xj>=1&&xj<=n&&yj+1>=1&&yj+1<=m)
                {
                    yj++;
                    vis[xj][yj]=1;
                }
                else fx=(fx+1)%4;
            }
             else if(fx==1)
            {

                if(mp[xj+1][yj]!='x'&&xj+1>=1&&xj+1<=n&&yj>=1&&yj<=m)
                {
                    xj++;
                    vis[xj][yj]=1;
                }
                else fx=(fx+1)%4;
            }
            else  if(fx==2)
            {

                if(mp[xj][yj-1]!='x'&&xj>=1&&xj<=n&&yj-1>=1&&yj-1<=m)
                {
                    yj--;
                    vis[xj][yj]=1;
                }
                else fx=(fx+1)%4;
            }
            else  if(fx==3)
            {

                if(mp[xj-1][yj]!='x'&&xj-1>=1&&xj-1<=n&&yj>=1&&yj<=m)
                {
                    xj--;
                    vis[xj][yj]=1;
                }
                else fx=(fx+1)%4;
            }

        }
         for(long long i=1;i<=n;i++)
        {

            for(long long j=1;j<=m;j++)
            {
                if(vis[i][j]==1)ans++;

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
