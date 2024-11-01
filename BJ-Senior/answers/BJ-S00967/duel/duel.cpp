#include <cstdio>
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
int vis[N];
void solve()
{
	int n = read(), ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int r = read();
		if (vis[r])
			++ans;
		vis[r]++;
	}
	int ans = max(vis[1], vis[2]) - min(vis[1], vis[2]);
	write(ans), putchar('\n');
}
signed main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	solve();
	return 0;
}
