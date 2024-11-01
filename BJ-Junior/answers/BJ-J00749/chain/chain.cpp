#include <iostream>
#include <sctdio>
using namespace std;

int l[1005];
int s[1005][2005];

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n, k, q;
		cin >> n >> k >> q;
		for(int j = 1; j <= n; j++)
		{
			cin >> l[j];
			for(int kk = 1; kk <= l[j]; kk++) cin >> s[j][kk];
		}
		
		bool f = false;
		int jj;
		for(int j = 1; j < l[1]; j++)
		{
			if(s[1][j] == 1)
			{
				f = true, jj = j;
				break;
		}
		if(!f)
		{
			cout << 0 << endl;
			continue;
		}
		bool ff = false;
		for(int a = 1; a < l[2]; a++)
		{
			for(int b = jj+1; b <= l[1]; b++)
			{
				if(s[2][a] == s[1][b])
				{
					cout << 0 << endl;
					ff = true;
					break;
				}
			}
		}
		if(ff == false) cout << 1 << endl;
	}
	return 0;
}