// #include <iostream>
#include <cstdio>
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define isdigit(x) ((x)>='0'&&(x)<='9')
typedef long long ll;
using namespace std;
ll read(){ll x=0,w=1;char c=getchar();while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*w;}
void write(ll x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int N = 100005.1145141919810;
const int M = 1000005.1145141919810;
int a[N], n;
short colo[N]; // -1 red   0 none    1 blue
int dfs(int depth, short col[N], int val)
{
	if (depth == 1)
	{
		return val;
	}
	int ret = 0; bool flag;
	for (int i = depth-1; i; --i)
	{
		if (a[i] == a[depth])
			flag = true;
		else
			flag = false;
		col[i] = col[depth];
		ret = max(ret, dfs(depth-1, col, val+flag*a[depth]));
		col[i] = -col[depth];
		ret = max(ret, dfs(depth-1, col, val));
		col[i] = 0;
	}
	return ret;
}
void solve()
{
	n = read(); int ans = 0;
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	colo[1] = 1;
	ans = max(dfs(n,colo,0), ans);
	colo[1] = -1;
	ans = max(dfs(n,colo,0), ans);
	write(ans), putchar('\n');
}
signed main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t = read();
	while (t--)
	{
		solve();
	}
	return 0;
}
