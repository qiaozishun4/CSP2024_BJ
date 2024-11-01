#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,t,k;
int a[N],base[N],x[10];
int c[N];
char d[25][100005];
int f[25][100005];
int logn(int y)
{
	if(y==1)return 0;
	return logn(ceil(y/2.0))+1;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	int k=logn(n);
	for(int i=1;i<=n;i++)
	{
		cin>>base[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
	}
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			a[i]=(base[i]^x[i%4]);
		}
		for(int i=0;i<=n;i++)
		{
			f[0][i]=i;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<(1<<(k-i));j++)
			{
				if(d[i][j]=='1')
				{
					if(a[f[i-1][j*2+1]+1]>=i)
					{
						f[i][j]=f[i-1][j*2+1];
						//cout<<i-1<<","<<j*2+1;
					}
					else
					{
						f[i][j]=f[i-1][j*2];
						//cout<<i-1<<","<<j*2;
					}
					//cout<<"->"<<i<<","<<j<<endl;
				}
				else
				{
					if(a[f[i-1][j*2]+1]>=i)
					{
						f[i][j]=f[i-1][j*2];
						//cout<<i-1<<","<<j*2;
					}
					else
					{
						f[i][j]=f[i-1][j*2+1];
						//cout<<i-1<<","<<j*2+1;
					}
					//cout<<"->"<<i<<","<<j<<endl;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int k1=logn(c[i]);
			ans=(ans^(i*(f[k1][0]+1)));
			//cout<<f[k1][0]+1<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
