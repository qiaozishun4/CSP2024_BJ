#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
ll t,n,m,k,x,y,d;
char a[1003][1003];
bool used[1003][1003];
void upd()
{
	ll xe=x,ye=y;
	if (d==0)ye++;
	if (d==1)xe++;
	if (d==2)ye--;
	if (d==3)xe--;
	if (xe>0&&xe<=n&&ye>0&&ye<=m&&a[xe][ye]=='.')
	{
		x=xe,y=ye;
	}
	else d=(d+1)%4;
}
int main()
{
	faster;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>k>>x>>y>>d;ll ans=0;
		for (ll i=1;i<=n;i++)
		{
			for (ll j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		used[x][y]=1;
		for (ll i=1;i<=k;i++)
		{
			upd();
			used[x][y]=1;
		}
		for (ll i=1;i<=n;i++)
		{
			for (ll j=1;j<=m;j++)
			{
				if (used[i][j])
				{
					ans++;
				}
				used[i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

