#include <iostream>
using namespace std;

int n, ans = 2e9, last, r[100005], cnt[100005];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> r[i];
	for(int i = 1; i <= n; i++)
		cnt[r[i]]++;
	last = cnt[1];
	for(int i = 1; i <= 1e5; i++)
	{
		last = max(0, last - cnt[i]);
		last += cnt[i];
	}
	cout << last << endl;

	return 0;
}