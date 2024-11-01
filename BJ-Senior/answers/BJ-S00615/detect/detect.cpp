#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int ans=0, w=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
			w=-1;

		c=getchar();
	}

	while('0'<=c && c<='9')
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans*w;
}

const int N=1e5+5;
const int M=1e6+5;

int l[N], r[N], cnt[M], pre[M];
bool can[N];

struct node
{
	int l,r;
};

node a[N];

bool cmp(node a,node b)
{
	return a.r<b.r;
}

void work()
{
	int n=read(), m=read(), L=read(), lim=read();
	for(int i=1;i<=n;i++)
	{
		int d=read(), v=read(), a=read();
		if(a<0)
		{
			if(v<=lim)
				l[i]=-1, r[i]=-1;
			else
			{
				a=-a;
				if((v*v-lim*lim)%(2*a)==0)
					l[i]=d, r[i]=min(L,d+(v*v-lim*lim)/(2*a)-1);
				else
					l[i]=d, r[i]=min(L,d+(v*v-lim*lim)/(2*a));
			}
		}
		else if(a>0)
		{
			if(v>lim)
				l[i]=d, r[i]=L;
			else
			{
				l[i]=d+(lim*lim-v*v)/(2*a)+1, r[i]=L;
				if(l[i]>r[i])
					l[i]=-1, r[i]=-1;
			}
		}
		else
		{
			if(v>lim)
				l[i]=d, r[i]=L;
			else
				l[i]=-1, r[i]=-1;
		}
	}

	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=m;i++)
	{
		int x=read();
		cnt[x]++;
	}

	int now=0;
	for(int i=1;i<=1000000;i++)
	{
		if(cnt[i])
			now=i;

		pre[i]=now;
		cnt[i] += cnt[i-1];
	}

	int ans1=0, ans2=0;
	for(int i=1;i<=n;i++)
	{
		if(l[i]==-1 && r[i]==-1)
			can[i]=false;
		else if(cnt[r[i]]==(l[i]==0?0:cnt[l[i]-1]))
			can[i]=false;
		else
			can[i]=true;

		ans1 += can[i];
	}

	int indx=0;
	for(int i=1;i<=n;i++)
		if(can[i])
			indx++, a[indx].l=l[i], a[indx].r=r[i];

	sort(a+1,a+indx+1,cmp);

	int Maxpos=-1;
	for(int i=1;i<=indx;i++)
		if(a[i].l>Maxpos)
			Maxpos=pre[a[i].r], ans2++;

	printf("%d %d\n",ans1,m-ans2);
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T=read();
	while(T--)
		work();
	return 0;
}