#include <bits/stdc++.h>
using namespace std;
const int N=1e3+7;
char a[N][N];
bool vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    int n,m,k,x0,y0,d0;
    int cnt=1;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        int x=x0,y=y0,d=d0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(d==0){
                if(x>=1 && x<=n && y+1>=1 && y+1<=m && a[x][y+1]=='.'){
                    if(!vis[x][y+1])
                    {
                        cnt++;
                        vis[x][y+1]=1;
                    }
                    y=y+1;
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(x+1>=1 && x+1<=n && y>=1 && y<=m && a[x+1][y]=='.'){
                    if(!vis[x+1][y])
                    {
                        cnt++;
                        vis[x+1][y]=1;
                    }
                    x=x+1;
                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(x>=1 && x<=n && y-1>=1 && y-1<=m && a[x][y-1]=='.'){
                    if(!vis[x][y-1])
                    {
                        cnt++;
                        vis[x][y-1]=1;
                    }
                    y=y-1;
                }
                else d=(d+1)%4;
            }
            else if(d==3){
                if(x-1>=1 && x-1<=n && y>=1 && y<=m && a[x-1][y]=='.'){
                    if(!vis[x-1][y])
                    {
                        cnt++;
                        vis[x-1][y]=1;
                    }
                    x=x-1;
                }
                else d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
        cnt=1;
    }
    return 0;
}
