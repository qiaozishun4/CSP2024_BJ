#include<bits/stdc++.h>
using namespace std;
#define int long long
int a_[131080], a[131080];
int c[100010];
int d[18][131080];
map<int, map<int, int>> winner;
int X;
void Cal(int l, int r, int id, int dep)
{
	if(l == r)
	{
		winner[l][r] = l;
		return;
	}
	int mid = l + r >> 1;
	Cal(l, mid, id * 2, dep - 1);
	Cal(mid + 1, r, id * 2 + 1, dep - 1);
	int winl = winner[l][mid];
	int winr = winner[mid + 1][r];
	if(d[dep][id])
	{
		if(a[winr] >= dep)
		{
			winner[l][r] = winr;
		}
		else
		{
			winner[l][r] = winl;
		}
	}
	else
	{
		if(a[winl] >= dep)
		{
			winner[l][r] = winl;
		}
		else
		{
			winner[l][r] = winr;
		}
	}
}
signed main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a_[i];
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> c[i];
	}
	X = ceil(log2(n));
	for(int i = 1; i <= X; i++)
	{
		for(int j = 0; j < pow(2, X - i); j++)
		{
			char ch;
			cin >> ch;
			d[i][j] = ch - 48;
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int x[4];
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for(int i = 1; i<= n; i++)
		{
			a[i] = a_[i] ^ x[i % 4];
		}
		winner.clear();
		Cal(1, 1 << (int)(floor(log2(n))), 0, (int)(floor(log2(n))));
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ans ^= i * winner[1][c[i]];
		}
		cout << ans << endl;
	}
	return 0;
}