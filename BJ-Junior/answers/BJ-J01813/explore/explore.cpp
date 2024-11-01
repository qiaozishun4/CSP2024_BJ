#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	int tt;
	cin >> tt;
	for(int t = 1;t <= tt;++t)
	{
		int cnt = 0;
		char c[1005][1005];
		bool f[1005][1005];
		memset(f,0,sizeof(f));
		int n,m,k;
		cin >> n >> m >> k;
		int cn,cm,d;
		cin >> cn >> cm >> d;
		f[cn][cm] = 1;
		for(int i = 0;i <= n;++i)
        {
            c[i][0] = 'x';
            c[i][m + 1] = 'x';
        }
        for(int i = 0;i <= m;++i)
        {
            c[0][i] = 'x';
            c[n + 1][i] = 'x';
        }
		for(int i = 1;i <= n;++i)
		{
			for(int j = 1;j <= m;++j)
			{
				cin >> c[i][j];
			}
		}
		for(int q = 1;q <= k;++q)
		{
			if(d == 3)
			{
				cn--;
				if(c[cn][cm] == 'x')
				{
					d = 0;
					cn++;
				}
				else
				{
					f[cn][cm] = 1;
				}
			}
			else if(d == 2)
			{
				cm--;
				if(c[cn][cm] == 'x')
				{
					d = 3;
					cm++;
				}
				else
				{
					f[cn][cm] = 1;
				}
			}
			else if(d == 1)
			{
				cn++;
				if(c[cn][cm] == 'x')
				{
					d = 2;
					cn--;
				}
				else
				{
					f[cn][cm] = 1;
				}
			}
			else
			{
				cm++;
				if(c[cn][cm] == 'x')
				{
					d = 1;
					cm--;
				}
				else
				{
					f[cn][cm] = 1;
				}
			}
		}
		for(int i = 1;i <= n;++i)
		{
			for(int j = 1;j <= m;++j)
			{
				cnt += f[i][j];
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
