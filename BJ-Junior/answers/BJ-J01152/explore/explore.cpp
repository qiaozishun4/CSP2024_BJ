#include<bits/stdc++.h>
using namespace std;
char c[1002][1002],vis[1002][1002];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
                vis[i][j]=false;
            }
        }
        int cnt=1,x=x0,y=y0,d=d0;
        vis[x][y]=true;
        for(int i=1;i<=k;i++)
        {
            int x1,y1;
            if(d==0)
                x1=x,y1=y+1;
            if(d==1)
                x1=x+1,y1=y;
            if(d==2)
                x1=x,y1=y-1;
            if(d==3)
                x1=x-1,y1=y;
            if(x1>=1&&y1>=1&&x1<=n&&y1<=m&&c[x1][y1]=='.')
            {
                x=x1;
                y=y1;
                if(vis[x][y]==false)
                {
                    cnt++;
                    vis[x][y]=true;
                }
            }
            else
            {
                int d1=(d+1)%4;
                d=d1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}