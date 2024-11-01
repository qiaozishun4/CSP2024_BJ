#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int T;
int n,m,k,X0,Y0,d;
char a[N][N];
bool vis[N][N];
inline bool vaild(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='.';
}
inline void Work()
{   
    memset(vis,false,sizeof(vis));
    cin >> n >> m >> k;
    cin >> X0 >> Y0 >> d;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin >> a[i][j];
    int x=X0,y=Y0,X1=0,Y1=0,D=d,ans=0;
    vis[x][y]=true,ans++;
    for(int i=1;i<=k;i++)
    {
        X1=x,Y1=y;
        if(!D)Y1++;
        else if(D==1)X1++;
        else if(D==2)Y1--;
        else X1--;
        if(vaild(X1,Y1))
        {
            x=X1,y=Y1;
            if(!vis[x][y])vis[x][y]=true,ans++;
        }
        else D=(D+1)%4;
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T--)Work();
    return 0;
}