#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct car
{
	int d, v, a;
}c[100010];
int p[100010];

struct jihe
{
	double s, e;
	bool is_s_open, is_e_open;
};

bool isin(int p, jihe a)
{
	bool ans;
	if (a.is_s_open)
		ans = (a.s < p);
	else
		ans = (a.s <= p);
	if (a.is_e_open)
		ans = (p < a.e) && ans;
	else
		ans = (p <= a.e) && ans;
	return ans;
}

bool find(int p[], jihe overspeed, int m, pair<int, int>& a)
{
	// int l = 0, r = m + 1;
	// while (l < r)
	// {
	// 	// printf("%d %d\n", l, r);
	// 	int mid = (l + r) >> 1;
	// 	if (fl <= p[mid] && p[mid] <= fr)
	// 		return true;
	// 	else if (fr < p[mid])
	// 		r = mid;
	// 	else if (p[mid] < fl)
	// 		l = mid + 1;
	// 	else
	// 		printf("WTF!!\n");
	// }
	// return false;
	vector<int> tmp;
	for (int i = 1; i <= m; i++)
		if (isin(p[i], overspeed))
			tmp.push_back(i);
	if (tmp.size() > 0)
	{
		a.first = tmp[0];
		a.second = tmp[tmp.size() - 1];
		return true;
	}
	return false;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int T;
	scanf("%d", &T);
	// T = 1;
	while (T--)
	{
		int n, m, L, V;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
		for (int i = 1; i <= m; i++)
			scanf("%d", p + i);
		int cnt = 0;
		vector<pair<int, int> > overspeeds;
		for (int i = 1; i <= n; i++)
		{
			pair<int, int> tmp;
			if (c[i].a == 0)
			{
				if (c[i].v > V && c[i].d <= p[m])
					cnt++, overspeeds.push_back({c[i].d, L});
			}
			else if (c[i].a > 0)
			{
				double over_speed_delta_s;
				over_speed_delta_s = (pow(V, 2) - pow(c[i].v, 2)) / 2.0 / (double)c[i].a;
				jihe overspeed;
				overspeed.s = over_speed_delta_s + c[i].d, overspeed.is_s_open = true;
				overspeed.e = L, overspeed.is_e_open = false;
				if (find(p, overspeed, m, tmp))
				{
					cnt++;
					overspeeds.push_back(tmp);
				}
				// cout << overspeed.s << ' ' << overspeed.e << ' ' << find(p, overspeed, m) << endl;
			}
			else if (c[i].a < 0 && c[i].v > V)
			{
				double over_speed_delta_s;
				over_speed_delta_s = (pow(V, 2) - pow(c[i].v, 2)) / 2.0 / (double)c[i].a;
				jihe overspeed;
				overspeed.s = c[i].d, overspeed.is_s_open = false;
				overspeed.e = c[i].d + over_speed_delta_s, overspeed.is_e_open = true;
				if (find(p, overspeed, m, tmp))
				{
					cnt++;
					overspeeds.push_back(tmp);
				}
				// cout << overspeed.s << ' ' << overspeed.e << ' ' << endl;
			}
		}
		// for (pair<int, int> i : overspeeds)
		// 	printf("%d %d\n", i.first, i.second);
		sort(overspeeds.begin(), overspeeds.end(), cmp);
		
		int ans = 0, nowp;
		if (overspeeds.size() == 0)
			goto out;
		ans = 1;
		nowp = overspeeds[0].second;
		for (int i = 1; i < overspeeds.size(); i++)
		{
			if (nowp < overspeeds[i].first)
				ans++, nowp = overspeeds[i].second;
		}
		out: printf("%d %d\n", cnt, m - ans);
	}
}