#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
template<typename... Args>void print(Args... args){int write[] = {(cout << args, 0)...};}
int t, n, m, L, V, p[100005], sum, ans;
bool book[100005], flag;
struct node
{
	int d, v, a;
};
vector<node> car(100005);
int IsLimitExceed(int CarId, int CgqId) // -1: 不知道，说明该检测器无法检测到该汽车, 0: 未超速, 1: 超速
{
	node nc = car[CarId];
	if(p[CgqId] - nc.d < 0) return -1;
	if(double(nc.v * nc.v) + 2 * double(nc.a) * double(p[CgqId] - nc.d) <= 0) return -1;
	double NowSpeed = 1.00 * sqrt(double(nc.v * nc.v) + 2 * double(nc.a) * double(p[CgqId] - nc.d));
	// print("CarId: ", CarId, ", CgqId: ", CgqId, " NowSpeed: ", NowSpeed, " IsLimitExceed: ");
	// if(NowSpeed > double(V) * 1.00) print("yes\n");
	// else print("no\n");
	if(NowSpeed > double(V) * 1.00) return 1;
	else return 0;
}
void dfs(bool book[], int deep)
{
	if(deep == m + 1)
	{
		int kk = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(book[j] == true && IsLimitExceed(i, j) == 1)
				{
					kk++;
					break;
				}
			}
		}
		if(sum == kk)
		{
			int gg = 0;
			for(int i = 1; i < deep; i++) if(book[i] == false) gg++;
			ans = max(ans, gg);
		}
	}
	else
	{
		book[deep] = true;
		dfs(book, deep + 1);
		book[deep] = false;
		dfs(book, deep + 1);
	}
}
double LastCgq(int CarId, bool stats)
{
	node nc = car[CarId];
	return double(double(double(2 * nc.a * nc.d) - double(nc.v * nc.v) + double(V * V)) / double(2 * nc.a)) * 1.00, double();
}
double LastCgq2(int CarId)
{
	node nc = car[CarId];
	return double(double(double(nc.v * nc.v) - double(V * V) - double(2 * nc.a * nc.d)) / double(2 * nc.a)) * 1.00, double();
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		sum = 0, ans = 0, flag = true;
		cin >> n >> m >> L >> V;
		for(int i = 1; i <= n; i++)
		{
			cin >> car[i].d >> car[i].v >> car[i].a;
		}
		for(int i = 1; i <= m; i++) cin >> p[i];
		for(int i = 1; i <= n; i++)
		{
			if(car[i].a != 0)
			{
				flag = false;
				break;
			}
		}
		if(flag) // 特殊性质A: a_i = 0
		{
			ans = m - 1;
			sum = 0;
			for(int i = 1; i <= n; i++) if(IsLimitExceed(i, m) == 1) sum++;
		}
		else
		{
			flag = true;
			for(int i = 1; i <= n; i++)
			{
				if(car[i].a <= 0)
				{
					flag = false;
					break;
				}
			}
			if(flag) // 特殊性质b: a_i > 0
			{
				double maxn = LastCgq(1, true);
				for(int i = 2; i <= n; i++)
				{
					maxn = max(maxn, LastCgq(i, true));
				}
				for(int i = m; i >= 1; i--)
				{
					if(maxn >= double(p[i]) * 1.0)
					{
						ans = i - 1;
						break;
					}
				}
				for(int i = 1; i <= n; i++)
				{
					if(IsLimitExceed(i, ans + 1) == 1)
					{
						sum++;
					}
				}
			}
			else
			{
				flag = true;
				for(int i = 1; i <= n; i++)
				{
					if(car[i].a >= 0)
					{
						flag = false;
						break;
					}
				}
				if(flag) // 特殊性质c: a_i < 0
				{
					double minn = LastCgq2(1);
					for(int i = 2; i <= n; i++)
					{
						minn = min(minn, LastCgq2(i));
					}
					for(int i = m; i >= 1; i--)
					{
						if(minn >= double(p[i]) * 1.0)
						{
							ans = m - i;
							break;
						}
					}
					for(int i = 1; i <= n; i++)
					{
						if(IsLimitExceed(i, m - ans) == 1)
						{
							sum++;
						}
					}
				}
				else // dfs暴力
				{
					for(int i = 1; i <= n; i++)
					{
						for(int j = 1; j <= m; j++)
						{
							if(IsLimitExceed(i, j) == 1)
							{
								sum++;
								break;
							}
						}
					}
					dfs(book, 1);
				}
			}
		}
		cout << sum << " " << ans << endl;
	}
	return 0;
}