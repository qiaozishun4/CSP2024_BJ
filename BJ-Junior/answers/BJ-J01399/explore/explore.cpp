#include <iostream>
#include <string>
#include <map>
#define int long long
using namespace std;
int t, n, m, k, d, ans;
string mp[1005], vis[1005];
struct node
{
	int x, y;
};
node ppp;
void GetNextPos()
{
	node next = ppp;
	if(d == 0)
	{
		next.y++;
	}
	else if(d == 1)
	{
		next.x++;
	}
	else if(d == 2)
	{
		next.y--;
	}
	else if(d == 3)
	{
		next.x--;
	}
	if(next.x < 1 || next.x > n || next.y < 1 || next.y > m)
	{
		next = ppp;
		d = (d + 1) % 4;
	}
	else if(mp[next.x][next.y] == 'x')
	{
		next = ppp;
		d = (d + 1) % 4;
	}
	ppp = next;
	if(vis[ppp.x][ppp.y] != 'h')
	{
		vis[ppp.x][ppp.y] = 'h';
		ans++;
	}
}
signed main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> m >> k >> ppp.x >> ppp.y >> d;
		// cout << n << " " << m << " " << k << " " << ppp.x << " " << ppp.y << " " << d << endl;
		for(int i = 1; i <= n; i++)
		{
			cin >> mp[i];
			mp[i] = " " + mp[i];
			vis[i] = mp[i];
		}
		if(vis[ppp.x][ppp.y] != 'h')
		{
			vis[ppp.x][ppp.y] = 'h';
			ans++;
		}
		// cout << "{" << ppp.x << ", " << ppp.y << ", " << mp[ppp.x][ppp.y] << "}\n";
		for(int i = 1; i <= k; i++)
		{
			GetNextPos();
			// cout << "{" << ppp.x << ", " << ppp.y << ", " << mp[ppp.x][ppp.y] << "}\n";
		}
		cout << ans << endl;
	}
	return 0;
}