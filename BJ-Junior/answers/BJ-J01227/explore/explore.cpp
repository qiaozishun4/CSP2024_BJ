#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k,T,x,y,d;
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        int cnt=1;
        vis[x][y]=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        while(k--)
        {

                int tx=x+dx[d],ty=y+dy[d];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='.')
                {
                    if(!vis[tx][ty])
                        cnt++;
                    x=tx,y=ty;
                    vis[tx][ty]=true;
                }
                else
                    d=(d+1)%4;

        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
