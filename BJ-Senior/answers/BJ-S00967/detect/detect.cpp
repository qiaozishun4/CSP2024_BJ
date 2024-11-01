#include <cstdio>
// #include <algorithm>
// #include <iostream>
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define isdigit(x) ((x)>='0'&&(x)<='9')
typedef long long ll;
using namespace std;
ll read(){ll x=0,w=1;char c=getchar();while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*w;}
void write(ll x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int N = 100005.1145141919810;
const int inf = 114514.1919810;
int n, m, l, V, p[N];
struct Car{
	int d;
	short v;
	short a;
}car[N];
void solve()
{
	n=read(), m=read(), l=read(), V=read();
	int V2 = V*V, mxa=-inf, mna=inf;
	for (int i = 1; i <= n; ++i)
	{
		car[i].d=read(), car[i].v=read(), car[i].a=read();
		mxa = max(mxa, car[i].a);
		mna = min(mna, car[i].a);
	}
	for (int i = 1; i <= m; ++i)
		p[i] = read();
	// sort(p+1, p+n+1);
	int tot = 0, toff = 0;
	if (mxa == 0 && mna == 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			int dx = p[m] - car[i].d;
			if (dx < 0) continue;
			int v2 = car[i].v*car[i].v;
			if (v2 > V2)
				++tot;
		}
		write(tot), putchar(' ');
		if (!tot)
			write(m);
		else
			write(m-1);
		putchar('\n');
		return;
	}
	if (mxa <= 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			int dx = p[m] - car[i].d;
			if (dx < 0) continue;
			int dx = p[1] - car[i].d;
			if (dx < 0) continue;
			int v2 = car[i].v*car[i].v + 2*car[i].a*dx;
			if (v2 > V2)
				++tot;
		}
		write(tot), putchar(' ');
		if (!tot)
			write(m);
		else
			write(m-1);
		putchar('\n');
		return;
	}
	if (mxa >= 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			int dx = p[m] - car[i].d;
			if (dx < 0) continue;
			int v2 = car[i].v*car[i].v + 2*car[i].a*dx;
			if (v2 > V2)
				++tot;
		}
		write(tot), putchar(' ');
		if (!tot)
			write(m);
		else
			write(m-1);
		putchar('\n');
		return;
	}
	bool det[N][N], f0 = true, f1 = true;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int dx = p[i] - car[j].d;
			if (dx < 0) continue;
			int v2 = car[j].v*car[j].v + 2*car[j].a*dx;
			if (v2 > V2)
			{
				++tot;
				det[j][i] = true;
				f0 = false;
			}
			else
			{
				f1 = false;
			}
		}
	if (f0)
	{
		write(0), putchar(' ');
		write(m), putchar('\n');
		return;
	}
	if (f1)
	{
		write(n), putchar(' ');
		write(m), putchar('\n');
		return;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			
		}
}
signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t = read();
	while (t--)
		solve();
	return 0;
}
