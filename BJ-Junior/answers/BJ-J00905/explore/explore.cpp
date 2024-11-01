#include "bits/stdc++.h"
using namespace std;
int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int t,fx,fy,fd,n,m,k;
char mp[1005][1005];
int cnt;
void mve()
{
	int nx = fx + d[fd][0];
	int ny = fy + d[fd][1];
	if((mp[nx][ny] == '.' || mp[nx][ny] == 'R') && nx > 0 && ny > 0 && nx <= n && ny <= m)
	{
		if(mp[nx][ny] == '.')
		{
			mp[nx][ny] = 'R';
			cnt++;
		}
		fx = nx,fy = ny;
	}
	else fd = (fd + 1) % 4;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		cnt = 1;
		cin >> n >> m >> k;
		cin >> fx >> fy >> fd;
		for(int i = 1;i <= n;i++)	for(int j = 1;j <= m;j++)	cin >> mp[i][j];
		mp[fx][fy] = 'R';
		for(int i = 1;i <= k;i++)	mve();
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
