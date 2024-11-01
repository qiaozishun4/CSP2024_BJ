#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,s,e,d,ans=0;
char a[1001][1001];
bool v[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int p,int d)
{
    v[x][y]=true;
    for(int i=d; p<=k; p++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]=='.' && !v[nx][ny])
        {
            v[nx][ny]=true;
            x=nx;
            y=ny;
        }
        else
        {
            i+=1;
            i%=4;
        }
    }
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--)
    {
        ans=0;
        cin >> n >> m >> k;
        cin >> s >> e >> d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                v[i][j]=false;
                cin >> a[i][j];
            }
        }
        dfs(s,e,1,d);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(v[i][j])
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
	return 0;
}
