#include <bits/stdc++.h>
using namespace std;
int T;
int n,m,k,ans;
char a[1005][1005];
int dis[1005][1005][4],vis[1005][1005];
void dfs(int x,int y,int d,int k1)
{
	if(k1 == k) return;
	int p1 = 0,p2 = 0;
	if(d == 0) p2 = 1;
	else if(d == 1) p1 = 1;
	else if(d == 2) p2 = -1;
	else p1 = -1;
	int nex = x + p1,ney = y + p2;
	if(nex >= 1 && nex <= n && ney >= 1 && ney <= m && a[nex][ney] == '.' && !dis[nex][ney][d])
	{
		if(!vis[nex][ney]) ans++,vis[nex][ney] = 1;
		dis[nex][ney][d] = 1;
		dfs(nex,ney,d,k1 + 1);
	}
	else
	{
		dis[x][y][(d+1)%4] = 1;
		dfs(x,y,(d + 1) % 4,k1 + 1);
	}
	/*else if(!dis[x][y][(d+1)%4])
	{
		return;
	}*/
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--)
    {
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		ans = 0;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		if(k > 170000)
        {
            if(d == 0)
            {
                cout << m - y + 1;
            }
            else if(d == 1)
            {
                cout << n - x + 1;
            }
            else if(d == 2)
            {
                cout << y - 1 + 1;
            }
            else
            {
                cout << x - 1 + 1;
            }
            cout << endl;
            continue;
        }
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i]+1;
		}
		dis[x][y][d] = 1,vis[x][y] = 1,ans++;
		dfs(x,y,d,0);
		cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
