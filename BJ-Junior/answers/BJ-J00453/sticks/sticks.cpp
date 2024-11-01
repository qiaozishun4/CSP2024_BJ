#include <bits/stdc++.h>
using namespace std;
typedef unsigned 
long long ull;
const int N = 10010 , M = 110;
ull cnt[N] , minn[M];
int a[20] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int t(int x)
{
	int cnt = 0;
	while(x > 0)
	{
		x /= 10;
		cnt++;
	}
	return cnt;
}
int p(int n)
{
	int mul = 1;
	for(int i = 1;i <= n;i++)
	{
		mul *= 10;
	}
	return mul;
}
void init()
{
	for(ull i = 1;i <= N - 10;i++)
	{
		int x = i;
		while(x > 0)
		{
			int now = x % 10;
			cnt[i] += a[now];
			x /= 10;
		}
		minn[cnt[i]] = min(minn[cnt[i]] , i);
	}
}
int main()
{
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	memset(minn , 0x3f , sizeof(minn));
	int T;
	cin >> T;
	init();
	while(T--)
	{
		int n;
		cin >> n;
		if(n == 1 || n == 0)
		{
			cout << -1 << endl;
			continue;
		}
		if(n % 7 == 0)
		{
			for(int i = 1;i <= n / 7;i++)
			{
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n % 7 == 1)
		{
			cout << 19;
			for(int i = 1;i <= n / 7 - 2;i++)
			{
				cout << 8;
			}
			cout << endl;
			continue;
		}
		else if(n < 200)
		{
			cout << minn[n] << endl;
			continue;
		}
	}
	return 0;
}
