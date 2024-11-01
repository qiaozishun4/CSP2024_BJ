#include<bits/stdc++.h>
using namespace std;
int dy[5]={1,0,-1,0};
int dx[5]={0,1,0,-1};
char ma[1010][1010];
int fg[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int ans=0;
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)
            {
                ma[i][j]=' ';
                fg[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ma[i][j];
            }
           // cout<<56;
        }
        while(k--)
        {
           //cout<<78576784;
            fg[x][y]=1;
           // cout<<x<<" "<<y<<endl;
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m||ma[nx][ny]=='x')
            {
                d=(d+1)%4;
               // cout<<d<<endl;
            }
            else{
                    //cout<<k;
                x=nx;
                y=ny;
        //    cout<<x<<" "<<y<<endl;
            }
        }
        fg[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               // cout<<fg[i][j]<<" ";
                if(fg[i][j]==1)
                {
                    ans++;
                }
            }
           //cout<<endl;
        }
        cout<<ans;
    }
    return 0;
}