#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, L, V, car_num, p_num, cnt, p[N];
struct Node
{
	int bg_place, bg_speed, add_speed;
}car[N];
struct NNode
{
	int l, r;
}vis[N];
int main ()
{
	freopen ("detect.in", "r", stdin);
	freopen ("detect.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		car_num = p_num = 0;
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++)
			cin >> car[i].bg_place >> car[i].bg_speed >> car[i].add_speed;
		for (int i = 1; i <= m; i++)
			cin >> p[i];
		sort (p + 1, p + 1 + m);
		if (car[1].add_speed == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (car[i].bg_speed > V && car[i].bg_place <= p[m])
					car_num ++;
			}
			cout << car_num << " " << m - 1 << endl;
		}
		else
			cout << n << " " << m << endl;
	}
	return 0;
}