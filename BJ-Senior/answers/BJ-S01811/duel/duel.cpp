#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100000;
int box[N + 10];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, x, ans = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		box[x]++;
	}
	for (int i = 1; i <= N; i++)
	{
		ans = max(ans, box[i]);
	}
	cout << ans << endl;
	return 0;
}