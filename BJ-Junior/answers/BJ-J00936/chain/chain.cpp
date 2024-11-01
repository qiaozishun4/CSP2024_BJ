#include <bits/stdc++.h>
using namespace std;

int d[1010][1010],r,c;
struct node
{
	bool op;
	int idex;
}h[200010];
bool ans;

int main()
{
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out" , "w" , stdout);
	int T;
	cin >> T;
	while (T --)
	{
		memset(h , 0 , sizeof(h));
		int n,k,q;
		cin >> n >> k >> q;
		for (int i = 1;i <= n;i++)
		{
			int m;
			cin >> m;
			for (int j = 1;j <= m;j++)
			{
				cin >> d[i][j];
				h[d[i][j]].op = true;
			}
		}
		while (q --)
		{
			cin >> r >> c;
			if (h[c].op == 0)
			{
				cout <<0 <<endl;
				continue;
			}
			bool a = 0,b = 0;
			for (int i = 1;i <= n;i++)
			{
				int j = 1;
				while (d[i][j ++] != 0)
					if (d[i][j] == 1) a = 1;
					else if (d[i][j] == c && j > 1 && a == 1) b = 1;
			}
			cout<< (a && b) <<endl;
		}
	}
	return 0;
}
