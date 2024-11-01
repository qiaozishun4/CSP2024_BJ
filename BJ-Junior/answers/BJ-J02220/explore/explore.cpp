#include<bits/stdc++.h>
using namespace std;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        bool a[n+10][m+10];
        memset(a,0,sizeof(a));
        bool b[n+10][m+10];
        memset(b,0,sizeof(b));
        int x,y,d,cnt=0;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char l;
                cin>>l;
                a[i][j]=(l=='.');
            }
        }
        for(int i=1;i<=k;i++)
        {
            b[x][y]=1;
            if(d==0)
            {
                if(a[x+dx[d]][y+dy[d]]/*&&x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m*/)
                {
                    x+=dx[d];
                    y+=dy[d];
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(a[x+dx[d]][y+dy[d]]/*&&x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m*/)
                {
                    x+=dx[d];
                    y+=dy[d];
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(a[x+dx[d]][y+dy[d]]/*&&x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m*/)
                {
                    x+=dx[d];
                    y+=dy[d];
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else
            {
                if(a[x+dx[d]][y+dy[d]]/*&&x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m*/)
                {
                    x+=dx[d];
                    y+=dy[d];
                }
                else
                {
                    d=(d+1)%4;
                }
            }
        }
        b[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cnt+=b[i][j];
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
