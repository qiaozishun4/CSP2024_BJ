// #include <iostream>
#include <cstdio>
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define isdigit(x) ((x)>='0'&&(x)<='9')
#define isbool(x) ((x)=='0'||(x)=='1')
typedef long long ll;
using namespace std;
ll read(){ll x=0,w=1;char c=getchar();while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*w;}
void write(ll x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

/*
bool readd()
{
	bool x[20];
	int tot = 0; char c = getchar();
	while (!isbool(c))
		c = getchar();
	while (isbool(c))
		x[tot++] = (c=='1');
	return x;
}
*/

int getk(int x)
{
	int l = 0, r = 31;
	while (l < r)
	{
		int mid = (l+r)>>1;
		int y = 1<<mid;
		if (x>y)
			l = mid+1;
		else
			r = mid;
	}
	return l;
}

const int N = 100005.1145141919810;
int n, m, A[N], c[N], k, K;
bool d[20][20];
int x[5];
// 2^17=131072 > 1e5

/*
int lg[N];
void initlog()
{
	lg[1] = 0;
	for (int i = 2; i < N-1; ++i)
		lg[i] = lg[i>>1] + 1;
}
*/

void solve()
{
	x[0]=read(), x[1]=read(), x[2]=read(), x[3]=read();
	int a[N];
	for (int i = 1; i <= n; ++i)
		a[i] = A[i] ^ (x[i%4]);
	for (int i = 1; i <= m; ++i)
	{
		int ans = 0;
		int k = getk(c[i]);
		for (int j = 1; j <= k; ++j)
		{
			for (int r = 1; r <= (1<<j); r+=2)
			if (d[r])
			{
				if (a[r+1]>=j)
					++ans;
			}
			else
				if (a[r]>=j)
					++ans;
		}
		write(ans), putchar('\n');
	}
}
signed main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	n = read(), m = read();
	K = getk(n);
	// k = lg[n];
	for (int i = 1; i <= n; ++i)
		A[i] = read();
	for (int i = 1; i <= m; ++i)
		c[i] = read();
	for (int i = 1; i <= K; ++i)
	{
		int tot = 0; char c = getchar();
		while (!isbool(c))
			c = getchar();
		while (isbool(c))
			d[i][tot++] = (c=='1');
	}
	int t = read();
	while (t--)
		solve();
	return 0;
}
