#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 , M = 1e8 + 10;
vector<int> v[N];
bool vis[M];
int h[N];
int main()
{
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		memset(vis , 0 , sizeof(vis));
		for(int i = 1;i <= N;i++)
		{
			v[i].clear();
		}
		int n , k , q;
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			int l;
			cin >> l;
			for(int j = 1;j <= l;j++)
			{
				int ac;
				cin >> ac;
				v[i].push_back(ac);
				vis[ac] = 1;
			}
		}
		while(q--)
		{
			int r , c;
			cin >> r >> c;
			if(r == 1)
			{
				if(vis[c] == 1)
				{
					cout << 1 << endl;
					continue;
				}
				if(vis[c] == 0)
				{
					cout << 0 << endl;
					continue;
				}
			}
			cout << 1 << endl;
		}
	}
	return 0;
}
