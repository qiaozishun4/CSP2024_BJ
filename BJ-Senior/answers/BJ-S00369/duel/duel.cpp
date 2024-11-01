#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N] , h[N] , num[N];
bool vis[N];
bool cmp(int n1 , int n2)
{
	if(h[n1] != h[n2])
	{
		return h[n1] > h[n2];
	}
	return n1 > n2;
}
int main()
{
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	int n , cnt = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		h[a[i]]++;
		if(vis[a[i]] == 0)
		{
			num[++cnt] = a[i];
			vis[a[i]] = 1;
		}
	}
	sort(num + 1 , num + cnt + 1 , cmp);
	for(int i = 1;i < cnt;i++)
	{
		n -= h[num[i + 1]];
	}
	cout << n << endl;
	return 0;
}
