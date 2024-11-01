#include<bits/stdc++.h>
using namespace std;
bool land[1008][1008];
bool vis[1008][1008];
int k,n,m,x,y,d,cnt;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;cin>>T;
    while(T)
    {
        cin>>n>>m>>k>>x>>y>>d;
        cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                char a;cin>>a;
                land[i][j]=false;
                if(a=='.')
                land[i][j]=true;
                vis[i][j]=false;
            }
        vis[x][y]=true;
        for(int i=0;i<k;i++)
        {
            int x1=x+dx[d],y1=y+dy[d];
            if(1<=x1<=n&&1<=y1<=m&&land[x1][y1])
            {
                x=x1,y=y1;
                if(!vis[x][y])
                {
                    cnt++;vis[x][y]=true;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<cnt+1<<endl;
        T--;
    }
    return 0;
}