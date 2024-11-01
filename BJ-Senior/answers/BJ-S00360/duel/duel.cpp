#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int r[100010];
int r_[100010];
int box[100010];

int max(int qaq[], int s, int e, int &next)
{
	int maxn = -1;
	next = s;
	for (int i = s; i <= e; i++)
	{
		if (maxn < qaq[i])
		{
			next = i;
			maxn = qaq[i];
		}
	}
	return maxn;
}

int main(int args, char* argv[])
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", r + i);

	sort(r + 1, r + n + 1);
	// 归一化
	int cnt = 1;
	int last = r[1];
	for (int i = 1; i <= n; i++)
	{
		if (r[i] != last)
			cnt++, last = r[i];
		r_[i] = cnt;
		box[cnt]++;
	}
	// cout << box[1] << ' ' << box[2] << endl;
	
	// for (int i = 1; i <= cnt; i++)
	// 	printf("%d ", box[i]);
	// printf("\n");	
	int ans = 0;
	for (int i = cnt; i >= 1; i--)
	{
		if (box[i] == 0)
			continue;
		int &sum = box[i];
		int next = i - 1;
		while (sum != 0)
		{
			int killed = min(box[i], box[next]);
			ans += killed;
			sum -= killed;
			box[next] -= killed;
			next--;
		}
		// for (int j = 1; j <= cnt; j++)
		// 	printf("%d ", box[j]);
		// printf("\n\n\n");

	}
	// for (int i = 1; i <= cnt; i++)
	// 	printf("%d ", box[i]);
	printf("%d\n", n - ans);
	return 0;

}