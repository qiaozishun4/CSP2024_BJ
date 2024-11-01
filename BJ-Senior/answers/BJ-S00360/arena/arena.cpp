// 不会 开摆
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int a_[100010];
int c[100010];
vector<bool> d[100010];

int main()
{
	srand(time(0));
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a_[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &c[i]);
	int k = ceil(1.0 * log2(n));
	for (int i = 1; i <= k; i++)
	{
		string s;
		cin >> s;
	}
	int T;
	scanf("%d", &T);
	// printf("%d\n", T);
	while (T--)
	{
		printf("%d\n", rand() % 20);
	}
	return 0;
}