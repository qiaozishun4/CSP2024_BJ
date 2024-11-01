#include <bits/stdc++.h>
using namespace std;

const int N=(1<<18)+5;

int a[N], c[N], need[N], n, m, k, rt;
char t[20][N], s[N];
int X[10], v[N], val[N], state[N], LG2[(1<<21)+5];
long long ans[N], tot;
bool haveans[N];
bool del[N];

void clear(int x,int dep)
{
	if(del[x])
		return;

	del[x]=true;
	if(dep==0)
	{
		tot -= x-(1<<k)+1;
		return;
	}

	clear(x*2,dep-1);
	clear(x*2+1,dep-1);
}

void opt(int x,int dep)
{
	int to=(x<<1)+s[x]-'0', p=LG2[state[to]&(-state[to])];
	if(p<dep)
		state[x] = state[to^1];
	else
		state[x] = 0, clear(to^1,dep-1);

	state[x] |= ((state[to]>>dep)<<dep);
}

void calc(int x,int dep)
{
	int val=state[x];
	opt(x,dep);
	if(state[x]!=val && x!=rt)
		calc(x>>1,dep+1);
}

void dfs(int x,int dep,int lim)
{
	if(dep==0)
	{
		need[x]=lim;
		return;
	}

	if(s[x]=='0')
	{
		dfs(x*2,dep-1,max(lim,dep));
		dfs(x*2+1,dep-1,lim);
	}
	else
	{
		dfs(x*2,dep-1,lim);
		dfs(x*2+1,dep-1,max(lim,dep));
	}
}

void work()
{
	scanf("%d %d %d %d",&X[0],&X[1],&X[2],&X[3]);
	for(int i=1;i<=n;i++)
		a[i] = v[i]^X[i&3];

	for(int i=1;i<1<<(k+1);i++)
		state[i]=(1<<19)-1;

	memset(del,0,sizeof(del));
	memset(haveans,0,sizeof(haveans));
	rt=1<<k, tot=0;
	for(int i=0;i<=k;i++)
	{
		dfs(rt,i,0);

		for(int j=(i==0?1:((1<<(i-1))+1));j<=(1<<i);j++)
			tot += j;

		for(int j=1;j<=1<<i;j++)
		{
			int x=(1<<k)+j-1;
			if(a[j]<need[x] && !del[x])
				del[x]=true, tot -= j;

			int newstate=1<<min(a[j],19);
			if(state[x]!=newstate)
			{
				state[x]=newstate;
				if(x!=rt)
					calc(x>>1,1);
			}

			if(!haveans[j])
				haveans[j]=true, ans[j]=tot;
		}

		rt >>= 1;
		if(rt)
			opt(rt,i+1);
	}

	long long tot=0;
	for(int i=1;i<=m;i++)
		tot ^= i*ans[c[i]];
	printf("%lld\n",tot);
}

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	for(int i=0;i<21;i++)
		LG2[1<<i]=i;

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);

	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);

	k=0;
	while((1<<k)<n)
		k++;

	for(int i=1;i<=k;i++)
		scanf("%s",t[i]);

	for(int i=1;i<=k;i++)
		for(int j=1<<(i-1);j<(1<<i);j++)
			s[j]=t[k-i+1][j-(1<<(i-1))];

	int T;
	cin >> T;
	while(T--)
		work();
	return 0;
}