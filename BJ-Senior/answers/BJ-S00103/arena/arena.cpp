#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int NR=2e5+5;
int A[NR],Q[NR];
char s[20][NR];
int a[NR];
LL b[20][NR],c[20][NR];
int d[20][NR];
LL ans[NR];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",A+i);
	for(int i=1;i<=m;++i) scanf("%d",Q+i);
	int k=__lg(n*2-1);
	for(int i=1;i<=k;++i) scanf("%s",s[i]);
	int T;scanf("%d",&T);
	while(T--)
	{
		int X[4];for(int i=0;i<4;++i) scanf("%d",X+i);
		for(int i=0;i<n;++i) a[i]=A[i]^X[(i+1)%4];
		//for(int i=0;i<n;++i) printf("%d ",a[i]);
		//puts("");
		ans[0]=1;
		int nw=0;
		//printf("%d\n",k);
		for(int i=1;i<=k;++i)
		{
			for(int j=0;j<(1<<i-1);++j) 
			{
				c[0][j]=0;
				b[0][j]=j+1;
				d[0][j]=a[j];
				bool flag=1;
				int t=j;
				for(int u=1;u<=i;++u)
				{
					if(s[u][t>>1]-'0'==(t&1))
					{
						if(a[j]<u) {flag=0;break;}
					}
					t>>=1;
				}
				if(!flag) b[0][j]=0;
				//printf("%d %d ",b[0][j],c[0][j]);
			}
			for(int j=(1<<i-1);j<(1<<i);++j)
			{
				c[0][j]=j+1;
				b[0][j]=0;
				d[0][j]=0;
				//printf("%d %d ",b[0][j],c[0][j]);
			}
			//puts("");
			for(int j=1;j<=i;++j)
			{
				for(int u=0;u<(1<<i-j);++u)
				{
					if(c[j-1][u<<1|(s[j][u]-'0')])
					{
						c[j][u]=c[j-1][u<<1]+c[j-1][u<<1|1];
						b[j][u]=b[j-1][u<<1]+b[j-1][u<<1|1];
						d[j][u]=max(d[j-1][u<<1],d[j-1][u<<1|1]);
					}
					else if(b[j-1][u<<1|(s[j][u]-'0')]||d[j-1][u<<1|(s[j][u]-'0')]>=j)
					{
						c[j][u]=c[j-1][u<<1|(s[j][u]-'0')];
						b[j][u]=b[j-1][u<<1|(s[j][u]-'0')];
						d[j][u]=d[j-1][u<<1|(s[j][u]-'0')];
					}
					else
					{
						c[j][u]=c[j-1][u<<1|((s[j][u]-'0')^1)];
						b[j][u]=b[j-1][u<<1|((s[j][u]-'0')^1)];
						d[j][u]=d[j-1][u<<1|((s[j][u]-'0')^1)];
					}
					//printf("%d %d ",b[j][u],c[j][u]);
				}
				//puts("");
			}
			//puts("");
			for(int j=(1<<i-1);j<(1<<i);++j)
			{
				c[0][j]=0;
				b[0][j]=j+1;
				d[0][j]=a[j];
				bool flag=1;
				int t=j;
				for(int u=1;u<=i;++u)
				{
					if(s[u][t>>1]-'0'==(t&1))
					{
						if(a[j]<u) {flag=0;break;}
					}
					t>>=1;
				}
				if(!flag) b[0][j]=0;
				t=j>>1;
				for(int u=1;u<=i;++u)
				{
					if(c[u-1][t<<1|(s[u][t]-'0')])
					{
						c[u][t]=c[u-1][t<<1]+c[u-1][t<<1|1];
						b[u][t]=b[u-1][t<<1]+b[u-1][t<<1|1];
						d[u][t]=max(d[u-1][t<<1],d[u-1][t<<1|1]);
					}
					else if(b[u-1][t<<1|(s[u][t]-'0')]||d[u-1][t<<1|(s[u][t]-'0')]>=u)
					{
						c[u][t]=c[u-1][t<<1|(s[u][t]-'0')];
						b[u][t]=b[u-1][t<<1|(s[u][t]-'0')];
						d[u][t]=d[u-1][t<<1|(s[u][t]-'0')];
					}
					else
					{
						c[u][t]=c[u-1][t<<1|((s[u][t]-'0')^1)];
						b[u][t]=b[u-1][t<<1|((s[u][t]-'0')^1)];
						d[u][t]=d[u-1][t<<1|((s[u][t]-'0')^1)];
					}
					t>>=1;
				}
				ans[j]=b[i][0]+c[i][0];
				/*
				for(int j=0;j<=i;++j)
				{
					for(int u=0;u<(1<<i-j);++u)
					{
						printf("%d %d ",b[j][u],c[j][u]);
					}
					puts("");
				}
				*/
			}
				//puts("------");
		}
	//	for(int i=1;i<=m;++i) printf("%lld ",ans[Q[i]-1]);
		//puts("");
		LL anS=0;
		for(int i=1;i<=m;++i) anS^=ans[Q[i]-1]*i;
		printf("%lld\n",anS);
	}
	return 0;
}