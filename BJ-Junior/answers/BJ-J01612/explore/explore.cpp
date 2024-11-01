#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,k;
ll x,y,d;
char a[1010][1010];
int f[3010][3010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ll ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n+5;i++)
		{
			for(int j=1;j<=m+5;j++)
			{
				f[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		while(k--)
		{
			if(f[x][y]!=123443210)
			{
				ans++;
				f[x][y]=123443210;
			}
			ll dx,dy;
			if(d==0)
			{
				dx=x,dy=y+1;
			}
			if(d==1)
			{
				dx=x+1,dy=y;
			}
			if(d==2)
			{
				dx=x,dy=y-1;
			}
			if(d==3)
			{
				dx=x-1,dy=y;
			}	
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]=='.')
			{
				x=dx,y=dy;
			}
			else
			{
				d=(d+1)%4;
			}
			if(f[x][y]!=123443210)
			{
				ans++;
				f[x][y]=123443210;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
