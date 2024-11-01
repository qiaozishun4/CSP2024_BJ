#include <bits/stdc++.h>
using namespace std;
const int N = 1e3; 
int n , k , q , a[N + 5][2 * N + 5] , l[N + 5];
bool Solve1(int c)
{
	for(int i = 1;i <= n;i++)
	{
		int last1 = -1;
		for(int j = 1;j <= l[i];j++)
		{
			if(a[i][j] == 1) last1 = j;
			if(a[i][j] == c && last1 != -1 && j - last1 + 1 <= k && 2 <= j - last1 + 1) return 1;
		}
	}
	return 0;
} 
int main()
{
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			cin >> l[i];
			for(int j = 1;j <= l[i];j++) cin >> a[i][j];
		}
		while(q--)
		{
			int r , c;
			cin >> r >> c;
			if(r == 1) cout << Solve1(c) << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}