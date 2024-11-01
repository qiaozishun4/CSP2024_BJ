#include<bits/stdc++.h>
using namespace std;
int a[100007][200007];
int l[100007];
int ans=0;

void w(int r,int c,int k,int dangqianlun,int wei,int n,int shanglunren)
{
	if(dangqianlun==r&&wei==c) ans=1;
	else if(dangqianlun==r&&wei!=c) ans=0;
	for(int i=1;i<=n;i++) // ren
	{
		if(i!=shanglunren)
		{
			for(int j=1;j<=k;j++)
			{
				for(int weizi=1;weizi<=l[i]-k+1;weizi++)
				{
					if(a[i][weizi]==wei) w(r,c,k,dangqianlun+1,a[i][weizi+k-1],n,i);
				}
			}
		}
	}
	return;
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T ;
	for(int qw=1;qw<=T;qw++)
	{
		int n,k,q;
		cin >> n >> k >> q ;
		for(int i=1;i<=n;i++)
		{
			cin >> l[i] ;
			for(int j=1;j<=l[i];j++)
			{
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			int r,c; // r lun  zuihou c
			cin >> r >> c ;
			w(r,c,k,0,1,n,-1);
			cout << ans ;
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
