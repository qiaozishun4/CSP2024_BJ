#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n , a[N];
void Solve1()
{
	int cnt2 = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == 2)
		{
			cnt2++;
		}
	}
	int cnt1 = n - cnt2;
	if(cnt2 > cnt1)
	{
		cout << cnt2 << endl;
	}
	else
	{
		cout << n - cnt2 << endl;
	}
}
int main()
{
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	cin >> n;
	bool flag1 = 1;
	int bn , sn;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] > 2) flag1 = 0;
	}
	if(flag1)
	{
		Solve1();
		return 0;
	}
	sort(a + 1 , a + n + 1);
	int p = 1;
	for(int i = 2;i <= n;i++)
	{
		if(a[i] > a[p])
		{
			p++;
		}
	}
	cout << n - (p - 1) << endl;
	return 0;
}