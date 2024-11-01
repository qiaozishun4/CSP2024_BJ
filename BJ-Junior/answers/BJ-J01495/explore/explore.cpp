#include<bits/stdc++.h>
using namespace std;
#define int long long
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
char g[1005][1005];
bool f[1005][1005];
int n,m;
bool inb(int x,int y)
{
    return (x<=n&&x>=1&&y<=m&&y>=1);
}
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,k,i,j,x,y,d,cnt,fx,fy;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(g,'\0',sizeof(g));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        k++;
        while(k--)
        {
//            cout<<x<<' '<<y<<' '<<d<<'\n';
            if(inb(x,y)==1&&g[x][y]=='.')
            {
                f[x][y]=1;
            }
            else
            {
                x-=dx[d];
                y-=dy[d];
                d=(d+1)%4;
            }
            x+=dx[d];
            y+=dy[d];
        }
        cnt=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cnt+=f[i][j];
//                cout<<f[i][j];
            }
//            cout<<'\n';
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
