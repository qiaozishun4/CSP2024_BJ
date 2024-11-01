#include <iostream>
#include <bitset>

using namespace std;

const int N = 2e5 + 5;
int a[N];
int n;
bitset<N> st, zero;
int res = 0;

void dfs(int u)
{
	if(u > n)
	{
		int sum = 0;
		for(int i = 2; i <= n; i ++ )
		{
			int j = i - 1;
			while(j >= 1 && st[i] != st[j])
			{
				j -- ;
			}
			if(a[i] == a[j])
			{
				sum += a[i];
			}
		}
		res = max(res, sum);
		return ;
	}

	for(int i = 0; i <= 1; i ++ )
	{
		st[u] = i;
		dfs(u + 1);
	}
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 1; i <= n; i ++ )
		{
			cin>>a[i];
		}

		st = zero, res = 0;
		dfs(1);

		cout<<res<<endl;
	}

	return 0;
}