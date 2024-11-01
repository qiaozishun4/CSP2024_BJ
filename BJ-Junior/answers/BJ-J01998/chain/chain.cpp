#include <iostream>
#include <cstring>
using namespace std;

int a[1005][1005];
int r[100005];
int c[100005];
int m[1005];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		int n,k,q;
		cin >> n >> k >> q;
		for (int j = 1;j <= n;i++)
		{
			int l;
			cin >> l;
			m[j] = l;
			for (int k1 = 1;k1 <= l;k1++)
			{
				cin >> a[j][k1];
			}
		}
		for (int j = 1;j <= q;j++)
		{
			cin >> r[j];
			cin >> c[j];
		}
		
		for (int j = 1;j <= q;j++)
		{
			bool r1 = 0;
			for (int k1 = 1;k1 <= n;k1++)
			{
				bool r2 = 0,r3 = 0;
				for (int l = 1;l <= m[k1];l++)
				{
					if (a[k1][l] == 1)
					{
						r2 = 1;
					}
					if (a[k1][l] == c[j])
					{
						r3 = 1;
					}
				}
				if (r2 && r3)
				{
					r1 = 1;
				}
			}
			if (r1)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}