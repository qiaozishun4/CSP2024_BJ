#include <iostream>
#include <vector>
#define int long long
using namespace std;

int t, n, k, q, x, r, c;
struct node
{
	int l;
	vector<int> s;
}  a[100005];

signed main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].l;
			a[i].s.clear();
			for(int j = 1; j <= a[i].l; j++)
				cin >> x, a[i].s.push_back(x);
		}
		while(q--)
		{
			cin >> r >> c;
			if(r == 1)
			{
				bool flag = false;
				for(int i = 1; i <= n; i++)
					for(int j = 0; j < a[i].s.size(); j++)
						if(j != 0 && a[i].s[j] == c)
							for(int l = j - 1; l >= max(j - k + 1, 0ll); l--)
								if(a[i].s[l] == 1)
								{
									flag = true;
									goto finish;
								}
				finish: ;
				if(flag) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else cout << 0 << endl;
		}
	}

	return 0;
}