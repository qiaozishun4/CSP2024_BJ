#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int b[1010][1010];
int d[5][3]{{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,di,ans;
	cin>>t;
	for(int v=1;v<=t;v++)
	{
		ans=1;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=m;j++) 
			{
				a[i][j]=0;
				b[i][j]=0;
			}
		}
		cin>>n>>m>>k>>x>>y>>di;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=m;j++) 
			{
				char te;
				cin>>te;
				if(te=='.') b[i][j]=1;
			}
		}
		a[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			if(b[x+d[di][0]][y+d[di][1]]==1)
			{
				x+=d[di][0];
				y+=d[di][1];
				if(a[x][y]==0) ans++;
				a[x][y]=1;
			}
			else
			{
				di=(di+1)%4;
			}
		}
	cout<<ans<<endl;
	}
	return 0;
}
