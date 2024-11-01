#include<iostream>
#define MAXN 1010
using namespace std;

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int ans[10], count = 1;
	while(t--)
	{
		int n, m, k, x0, y0, d0;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		char c[MAXN][MAXN];
		bool flag[MAXN][MAXN];
		int cnt = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> c[i][j];
				flag[i][j] = false;
			}
		}
		flag[x0][y0] = true;
		for(int i = 1; i <= k; i++)
		{
			int px, py;
			if(d0 == 0) px = x0, py = y0 + 1;
			else if(d0 == 1) px = x0 + 1, py = y0;
			else if(d0 == 2) px = x0, py = y0 - 1;
			else px = x0 - 1, py = y0;
			if(px >= 1 && px <= n && py >= 1 && py <= m && c[px][py] != 'x')
			{
				x0 = px;
				y0 = py;
				if(!flag[x0][y0])
				{
					flag[x0][y0] = true;
					cnt++;
				}
			}
			else d0 = (d0 + 1) % 4;
		}
		ans[count] = cnt;
		count++;
	}
	for(int i = 1; i < count; i++) printf("%d\n", ans[i]);
	return 0;
}
