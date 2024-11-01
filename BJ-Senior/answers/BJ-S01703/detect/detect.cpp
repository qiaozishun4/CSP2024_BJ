#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n , m , L , V;
int p[N] , sp[N * 10];
struct Node
{
	int l , r;
} car[N];
int main()
{
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		memset(sp , 0 , sizeof(sp));
		memset(car , 0 , sizeof(car));
		cin >> n >> m >> L >> V;
		bool a0 = 1 , apos = 1;
		int cur = 0;
		for(int i = 1;i <= n;i++) 
		{
			int d , v , a;
			cin >> d >> v >> a;
			if(a <= 0) apos = 0;
			if(a != 0) a0 = 0;
			
			if(a == 0 && v > V)
			{
				cur++;
				car[cur].l = d;
				car[cur].r = L;
			}
			else if(a < 0 && v > V)
			{
				long long s;
				if((V * V - v * v) % (2 * a) == 0) s = (V * V - v * v) / (2 * a) - 1;
				else s = (V * V - v * v) / (2 * a);
				cur++;
				car[cur].l = d;
				car[cur].r = min(d + s , L);
			}
			else if(a > 0)
			{
				if(v > V)
				{
					cur++;
					car[cur].l = d;
					car[cur].r = L;
				}
				if(v == V)
				{
					cur++;
					car[cur].l = d + 1;
					car[cur].r = L;
				}
				if(v < V)
				{
					long long s = (V * V - v * v) / (2 * a) + 1;
					if(s <= L)
					{
						cur++;
						car[cur].l = d + s;
						car[cur].r = L;
					}
				}
				
			}
		}
		for(int i = 1;i <= m;i++)
		{
			cin >> p[i];
			sp[p[i]] = 1;
		}
		for(int i = 0;i <= L;i++)
		{
			if(sp[i]) sp[i] = sp[i - 1] + 1;
			else sp[i] = sp[i - 1];
		}
		int cnt = 0;
		for(int i = 1;i <= cur;i++)
		{
			int l = car[i].l , r = car[i].r;
			if(l == -1 || r == -1) continue; 
			if(sp[r] - sp[l - 1] >= 1)  cnt++;
		}
		cout << cnt << " ";
		if(cnt == 0) cout << m << endl;
		else if(a0 || apos) cout << m - 1 << endl;
	}
	return 0;
}