#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long minn = 1e15;
int x;

void dfs(int n, long long ans)
{
	if(n <= 0)
	{
		if(n == 0) minn = min(minn, ans);
		return;
	}
	for(int i = (n == x); i <= 9; i++) dfs(n-num[i], ans*10+i);
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		if(n % 7 == 0)
		{
			while(n)
			{
				cout << 8;
				n -= 7;
			}
			cout << endl;
			continue;
		}
		if(n % 7 == 1)
		{
			if(n == 1)
			{
				cout << -1 << endl;
				continue;
			}
			if(n == 8)
			{
				cout << 10 << endl;
				continue;
			}
			while(n > 14)
			{
				cout << 8;
				n -= 7;
			}
			cout << "01" << endl;
			continue;
		}
		x = n;
		dfs(n, 0);
		if(minn != 1e15) cout << minn << endl;
		else cout << -1 << endl;
		minn = 1e15;
	}
    return 0;
}