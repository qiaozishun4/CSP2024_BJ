#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[100010];
bool c[100010];
int ans;

void dfs(int u)
{
	if (u>n)
	{
		int p0=-1, p1=-1;
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if (c[i]==0)
			{
				if (p0!=-1)
					if (a[i]==a[p0])
						sum+=a[i];
				p0=i;
			}
			else if (c[i]==1)
			{
				if (p1!=-1)
					if (a[i]==a[p1])
						sum+=a[i];
				p1=i;
			}
		}
		if (sum>ans)
			ans=sum;
		return;
	}
	c[u]=0;
	dfs(u+1);
	c[u]=1;
	dfs(u+1);
}

void solve()
{
	scanf("%d", &n);
	for (int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	ans=0;
	dfs(1);
	printf("%d\n", ans);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}