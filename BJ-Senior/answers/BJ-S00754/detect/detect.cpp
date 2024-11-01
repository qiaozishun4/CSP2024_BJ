#include "bits/stdc++.h"
using namespace std;
int t,n,m,l,v,d[100005],u,p;
double ch[100005],a[100005];
bool su[100005];
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> l >> v;
		int cnt = 0, tmp = 0;
		memset(su,false,sizeof(su));
		for(int i = 1;i <= n;i++)
		{
			cin >> d[i] >> u >> a[i];
			if(a[i] == 0)
			{
				if(u > v) ch[i] = -1;
				if(u <= v) ch[i] = 0x3f3f3f3f;
				continue;
			}
			double k = (double)((v * v) - (u * u)) / (double)(2.0 * a[i]);
			ch[i] = d[i] + k;
		}
		for(int i = 1;i <= m;i++)
		{
			cin >> p;
			for(int j = 1;j <= n;j++)
			{
				if(a[j] < 0 && p >= d[j] && p <= ch[j] && ch[j] != 0x3f3f3f3f)
				{
					if(!su[i])
					{
						su[i] = 1;
						tmp++;
					}
					ch[j] = 0x3f3f3f3f;
					cnt++;
				}else  if(a[j] >= 0 && p >= ch[j] && ch[j] != 0x3f3f3f3f)
				{
					if(!su[i])
					{
						su[i] = 1;
						tmp++;
					}
					ch[j] = 0x3f3f3f3f;
					cnt++;
				}
			}
		}
		cout << cnt << ' ' << tmp << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
