#include <bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],e[100010],d[30][100010],x[4];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>c[i];
	double t1=int(log2(n));
	int t2;
	if(t1<log2(n))
		t2=t1+1;
	else
		t2=t1;
	for(i=1;i<=t2;i++)
	{
		long long l=(1ll<<(t2-i));
		for(j=1;j<=l;j++)
		{
			char c1;
			cin>>c1;
			d[i][j]=c1-'0';
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		long long ans=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=c[i];j++)
			{
				e[j]=j;
				b[j]=a[j]^x[j%4];
			}
			for(j=1;c[i]>1;j++)
			{
				for(k=2;k<=c[i];k+=2)
				{
					if(d[j][k/2])
					{
						if(b[e[k]]>=j)
							e[k/2]=e[k];
						else
							e[k/2]=e[k-1];
					}
					else
					{
						if(b[e[k-1]]>=j)
							e[k/2]=e[k-1];
						else
							e[k/2]=e[k];
					}
				}
				c[i]/=2;
			}
			ans^=i*e[1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
