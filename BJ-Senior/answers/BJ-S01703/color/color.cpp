#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m , a[N];
long long ans = -9e18;
bool col[N];
void DFS(int step)
{
	if(step > n)
	{
		int last0 = -1 , last1 = -1;
		long long sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(col[i] == 0)
			{
				if(last0 == -1 || a[i] != a[last0])
				{
					last0 = i;
					continue;
				}
				// cout << last0 << " " << i << ":" << a[i] << endl;
				last0 = i;
				sum += a[i];
			}
			if(col[i] == 1)
			{
				if(last1 == -1 || a[i] != a[last1])
				{
					last1 = i;
					continue;
				}
				// cout << last1 << " " << i << ":" << a[i] << endl;
				last1 = i;
				sum += a[i];
			}
		}
		ans = max(ans , sum);
		return ;
	}
	col[step] = 0;
	DFS(step + 1);
	col[step] = 1;
	DFS(step + 1);
}
int main()
{
	freopen("color.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if(n <= 15)
		{
			ans = -9e18;
			DFS(1);
			cout << ans << endl;
		}
	}
	return 0;
}