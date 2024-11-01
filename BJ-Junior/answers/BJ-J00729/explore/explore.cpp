#include<iostream>
#include<cstdio>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},N=1005;
char jung[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n,m,k,x,y,d;
    cin>>T;
    while (T--)
    {
        int res=0;
        cin>>n>>m>>k>>x>>y>>d;
        for (int i=0;i<=m+1;i++) jung[0][i]=jung[n+1][i]='x';
        for (int i=0;i<=n+1;i++) jung[i][0]=jung[i][m+1]='x';
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>jung[i][j];
        jung[x][y]='v';
        while (k--) if (jung[x+dx[d]][y+dy[d]]=='x') d++,d%=4; else x+=dx[d],y+=dy[d],jung[x][y]='v';
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (jung[i][j]=='v') res++;
        cout<<res<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
