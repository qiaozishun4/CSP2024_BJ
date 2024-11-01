#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int n, m, L, vm;
ll d[100010], v[100010], a[100010], p[100010];
int l[100010], r[100010];
int ans;
int mx;

bool shut[100010];

int calc()
{
	int tmp=0;
	for (int i=1;i<=n;i++)
	{
		if (l[i]==-1)
			continue;
		bool flag=0;
		for (int j=1;j<=m;j++)
		{
			if (shut[j])
				continue;
			if (l[i]<=p[j] && p[j]<=r[i])
			{
				flag=1;
				break;
			}
		}
		tmp+=flag;
	}
	return tmp;
}

void dfs(int u)
{
	if (u>m)
	{
		int num=0;
		for (int i=1;i<=m;i++)
			num+=shut[i];
		if (calc()==mx)
		{
			ans=max(ans, num);
			
		}
		return;
	}
	shut[u]=1;
	dfs(u+1);
	shut[u]=0;
	dfs(u+1);

}

void solve1()
{
	for (int i=1;i<=n;i++)
	{
		if (a[i]<0)
		{
			if (v[i]<=vm)
				l[i]=r[i]=-1;
			else
			{
				int move=(vm*vm-v[i]*v[i])/(2*a[i]);
				if ((vm*vm-v[i]*v[i])%(2*a[i])==0)
					move--;
				l[i]=d[i], r[i]=d[i]+move;
			}
		}
		else if (a[i]==0)
		{
			if (v[i]<=vm)
				l[i]=r[i]=-1;
			else
				l[i]=d[i], r[i]=L;
		}
		else
		{
			if (v[i]>vm)
				l[i]=d[i], r[i]=L;
			else
			{
				int move=ceil((vm*vm-v[i]*v[i])/(2.0*a[i]));
				if ((vm*vm-v[i]*v[i])%(2*a[i])==0)
					move++;
				if (d[i]+move>L)
					l[i]=r[i]=-1;
				else
					l[i]=d[i]+move, r[i]=L;
			}
		}
	}
	memset(shut, 0, sizeof(shut));
	mx=calc();
	ans=0;
	dfs(1);
	printf("%d %d\n", mx, ans);

}

int cnt;

void solve2()
{
	cnt=0;
	sort(p+1, p+m+1);
	int x=p[m];
	for (int i=1;i<=n;i++)
	{
		if (d[i]>x)
			continue;
		ll vx2=v[i]*v[i]+2*a[i]*(x-d[i]);
		if (vx2>vm*vm)
			cnt++;
	}
	if (cnt)
		printf("%d %d\n", cnt, m-1);
	else printf("%d %d\n", cnt, m);

}

void solve()
{
	scanf("%d%d%d%d", &n, &m, &L, &vm);
	memset(d, 0, sizeof(d));
	memset(v, 0, sizeof(v));
	memset(a, 0, sizeof(a));
	for (int i=1;i<=n;i++)
		scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
	for (int i=1;i<=m;i++)
		scanf("%lld", &p[i]);
	if (m<=20)
		solve1();
	else solve2();
}	

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}