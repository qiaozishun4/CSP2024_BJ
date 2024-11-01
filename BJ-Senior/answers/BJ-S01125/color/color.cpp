#include <bits/stdc++.h>
using namespace std;
int n;
long long c[100005],a[100005],b[100005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T ;
	while(T --)
	{
		cin >> n ;
		long long res = 0,now = 0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		for(int i=1;i<=( 1<< n);i ++)
		{
			now = 0;
			int x = i,s = 0;
			while(x != 0)
			{
				c[++s] = x % 2;
				x /= 2;
			}
			int lstb = 0,lstr = 0;
			for(int j=1;j<=n;j++)
			{
				if(c[j] == 0) 
				{
					if(a[j] == a[lstb])b[j] = a[lstb],now += a[lstb];
					lstb = j;
				}
				else
				{
					if(a[j] == a[lstr])b[j] = a[lstr],now += a[lstr];
					lstr = j;
				}
			}
			res = max(res,now);
		}
		cout << res << "\n";
	}
	return 0;
}