#include<bits/stdc++.h>
using namespace std;
int l[100005],r[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,v,t,x = 0;
		bool c = 0;
		cin >> n >> m >> v >> t;
		if(m == 0)
		{
			printf("0 0\n");
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			int p;
			cin >> l[i] >> r[i] >> p;
		}
		int a;
		for(int i = 1;i <= m;i++)
		{
			
			cin >> a;
		}
		for(int i = 1;i <= n;i++)
		{
			if(l[i] <= a && r[i] >= t)
				x++;
		}
		c = x;
		cout << x << ' ' << c << '\n';
	}
	return 0;
}
