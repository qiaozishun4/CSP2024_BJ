#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define reg register
#define fin freopen("explore.in","r",stdin);
#define fout freopen("explore.out","w",stdout);
using namespace std;
const int sx[15]={0,1,0,-1};
const int sy[15]={1,0,-1,0};
int tests,n,m,k,x,y,d;
bool a[1005][1005],vis[1005][1005];
int cnt;
string s[1005];
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tests;
    while(tests--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for(reg int i=1;i<=n;i++)
        {
            cin >> s[i];
            for(reg int j=1;j<=m;j++)
                a[i][j]=(s[i][j-1]=='.');
        }
        for(reg int i=1;i<=n;i++)
            for(reg int j=1;j<=m;j++)
                vis[i][j]=0;
        cnt=1;
        vis[x][y]=1;
        for(reg int i=1;i<=k;i++)
        {
            int nx=x+sx[d],ny=y+sy[d];
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]==1)
            {
                x=nx,y=ny;
                if(!vis[x][y])
                {
                    vis[x][y]=1;
                    cnt++;
                }
            }
            else
                d=(d+1)%4;
        }
        cout << cnt << endl;
    }
	return 0;
}
