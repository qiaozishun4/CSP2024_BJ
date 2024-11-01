#include<iostream>
using namespace std;
int N,n,m,a[1<<17],c[100010],T,X[4];
int f[1<<18],g[1<<18],h[1<<18],lim[1<<18],ans[1<<17];
char s[(1<<16)+10];
bool A[1<<17];
long long Ans[(1<<17)|1],ANS[100010];
inline void solve(int n,int m)
{
	for(int i=0;i<n;i++)
	{
		f[n|i]=i,g[n|i]=a[i];
	}
	int lg2=__lg(n);
	for(int i=lg2-1;i>=0;i--)
	{
		for(int j=1<<i;j<(1<<i+1);j++)
		{
			if(A[j-(1<<i)|(1<<m+i)])
			{
				f[j]=f[(j<<1)|1];
				g[j]=g[(j<<1)|(g[(j<<1)|1]>=lg2-i)];
			}
			else
			{
				bool t=g[j<<1]<lg2-i;
				f[j]=f[(j<<1)|t];
				g[j]=g[(j<<1)|t];
			}
		}
	}
	h[1]=f[1];
	for(int i=1;i<=lg2;i++)
	{
		for(int j=1<<i;j<(1<<i+1);j++)
		{
			h[j]=min(h[j>>1],f[j]);
			lim[j]=lim[j>>1]?lim[j>>1]:
			((A[(j-(1<<i)>>1)|(1<<m+i-1)]
			==(j&1))?lg2-i+1:0);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(h[n|i]<i)
		{
			ans[i]=h[n|i]-1;
			continue;
		}
		if(a[i]<lim[n|i])
		{
			ans[i]=i-1;
			continue;
		}
		ans[i]=n-1;
		for(int j=n|i,k=1;j>1;j>>=1,k++)
		{
			if(!(j&1)&&g[j|1]>=k&&
			A[(j>>1)-(1<<lg2-k)|(1<<m+lg2-k)])
			{
				ans[i]=f[j|1]-1;
				break;
			}
		}
	}
	for(int i=0;i<n;Ans[i++]=0);
	for(int i=0;i<n;i++)
	{
		Ans[0]+=i+1;
		Ans[ans[i]+1]-=i+1;
	}
	long long sum=0;
	for(int i=0;i<(n>>1);sum+=Ans[i++]);
	for(int i=n>>1;i<min(n,N);i++)
	{
		sum+=Ans[i];
		ANS[i]=sum;
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	N=n,n=1<<__lg(n-1)+1;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
		c[i]--;
	}
	for(int i=n>>1;i;i>>=1)
	{
		cin>>s;
		for(int j=0;j<i;j++)
		{
			A[i|j]=s[j]-'0';
		}
	}
	cin>>T;
	while(T--)
	{
		for(int i=0;i<4;i++)
		{
			cin>>X[i];
		}
		for(int i=0;i<N;i++)
		{
			a[i]^=X[i+1&3];
		}
		for(int i=n,j=0;i;
		solve(i,j++),i>>=1);
		long long ret=0;
		for(int i=1;i<=m;i++)
		{
			ret^=(long long)
			i*ANS[c[i]];
		}
		cout<<ret<<'\n';
		for(int i=0;i<N;i++)
		{
			a[i]^=X[i+1&3];
		}
	}
	return 0;
}