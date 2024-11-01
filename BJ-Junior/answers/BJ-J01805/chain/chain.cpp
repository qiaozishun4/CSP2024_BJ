#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> seq[100010];
int r[100010], c[100010];
int ans[100010];
void Solve()
{
	for(int i = 1; i <= 100000; i++)
	{
		seq[i].clear();
	}
	memset(ans, 0, sizeof(ans));
	int n, k, q;
	cin >> n >> k >> q;
	memset(a, 0, sizeof(a));
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		int l;
		cin >> l;
		for(int j = 1; j <= l; j++)
		{
			int x;
			cin >> x;
			seq[i].push_back(x);
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int cnt = 0;
	for(auto i : v)
	{	
		cnt++;
		a[i] = cnt;
	}
	for(int i = 1; i <= n; i++)
	{
		for(auto &j : seq[i])
		j = a[j];
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> r[i] >> c[i];
	}
	int maxn = *max_element(r + 1, r + q + 1);
	if(maxn <= 1)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < seq[i].size(); j++)
			{
				if(seq[i][j] == a[1])
				for(int kk = j + 1; kk < seq[i].size(); kk++)
				{
					if(kk - j + 1 > k)
					break;
					ans[seq[i][kk]] = 1;
				}
			}
		}
		for(int i = 1; i <= q; i++)
		{
			cout << ans[a[c[i]]] << endl;
		}
	}
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		Solve();
	}
	return 0;
}