#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int sx,sy,sd;
char a[1005][1005];
bool vis[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                vis[i][j]=false;
            }
        while(k--)
        {
            vis[sx][sy]=true;
            int nx=sx,ny=sy;
            if(sd==0) ny++;
            else if(sd==1) nx++;
            else if(sd==2) ny--;
            else nx--;
            if(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x')
            {
                sd=(sd+1)%4;
            }
            else
            {
                sx=nx,sy=ny;
                vis[sx][sy]=true;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j])
                    cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}
