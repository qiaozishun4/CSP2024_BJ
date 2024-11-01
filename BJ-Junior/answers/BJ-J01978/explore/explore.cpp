#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
ll ans=0;
char a[N][N];
bool vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,x,y,d;
    int t;
    cin>>t;

    while(t--)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        ans++;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(x>=1&&x<=n&&(y+1)>=1&&(y+1)<=m&&a[x][y+1]=='.')
                {
                    y+=1;
                    if(vis[x][y]==0)
                    {
                        ans++;
                        vis[x][y]=1;
                    }

                }
                else d=(d+1)%4;

            }
            else if(d==1)
            {
                if((x+1)>=1&&(x+1)<=n&&y>=1&&y<=m&&a[x+1][y]=='.')
                {
                    x+=1;
                    if(vis[x][y]==0)
                    {
                        ans++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;

            }
            else if(d==2)
            {
                if(x>=1&&x<=n&&(y-1)>=1&&(y-1)<=m&&a[x][y-1]=='.')
                {
                    y-=1;
                    if(vis[x][y]==0)
                    {
                        ans++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;

            }
            else
            {
                if((x-1)>=1&&(x-1)<=n&&y>=1&&y<=m&&a[x-1][y]=='.')
                {
                    x-=1;
                    if(vis[x][y]==0)
                    {
                        ans++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;
            }

        }
      /*  for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //if(vis[i][j]==1)
              //  {
//ans++;
               // }
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<ans<<endl;
    }

    return 0;
}
