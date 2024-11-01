#include<bits/stdc++.h>
#define MAXN 100010
#define inf 0x3f3f3f3f
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m, L, V;
		int d[MAXN], v[MAXN], a[MAXN], p[MAXN];
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &d[i], &v[i], &a[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &p[i]);
		sort(p + 1, p + m + 1, cmp);
		int cnt1 = 0, cnt2 = 0;
		int pw[MAXN];
		memset(pw, 0, sizeof(pw));
		for(int i = 1; i <= n; i++)
		{
			if(v[i] > V)
			{
				if(a[i] >= 0)
				{
					int flag = 0;
					for(int j = 1; j <= m; j++)
					{
						if(p[j] >= d[i])
						{
							pw[j]++;
							flag = 1;
						}
					}
					if(flag) cnt1++;
				}
				else
				{
					double dx = (pow(V, 2) - pow(v[i], 2)) / (2 * a[i]);
					for(int j = m; j >= 1; j--)
					{
						if(p[j] >= d[i] && p[j] < d[i] + dx)
						{
							pw[j]++;
							cnt1++;
							break;
						}
					}
				}
			}
			else if(v[i] == V)
			{
				if(a[i] > 0)
				{
					int flag = 0;
					for(int j = 1; j <= m; j++)
					{
						if(p[j] > d[i])
						{
							pw[j]++;
							flag = 1;
						}
					}
					if(flag) cnt1++;
				}
			}
			else
			{
				if(a[i] > 0)
				{
					double dx = (pow(V, 2) - pow(v[i], 2)) / (2 * a[i]);
					int flag = 0;
					for(int j = 1; j <= m; j++)
					{
						if(p[j] > d[i] + dx)
						{
							pw[j]++;
							flag = 1;
						}
					}
					if(flag) cnt1++;
				}
			}
		}
		int maxp = -inf;
		for(int i = 1; i <= m; i++) maxp = max(maxp, pw[i]);
		for(int i = 1; i <= m; i++) if(pw[i] != maxp) cnt2++;
		printf("%d %d\n", cnt1, cnt2);
		//for(int i = 1; i <= m; i++) printf("%d ", pw[i]);
	}
	return 0;
}
