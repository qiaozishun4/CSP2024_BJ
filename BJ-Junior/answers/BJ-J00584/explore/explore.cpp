#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],ans[10005][10005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		int n,m,i,j,k,x,y,d,sum=1;
		char op;
		cin>>n>>m>>k>>x>>y>>d;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>op;
				if(op=='.') a[i][j]=0;
				else a[i][j]=1;
			}
		}
		for(i=1;i<=k;i++)
		{
			if(d==0)
			{
				if(y+1>0 && y+1<=m && a[x][y+1]==0)
				{
					ans[x][y+1]++;
					y++;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else if(d==1)
			{
				if(x+1>0 && x+1<=n && a[x+1][y]==0)
				{
					ans[x+1][y]++;
					x++;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else if(d==2)
			{
				if(y-1>0 && y-1<=m && a[x][y-1]==0)
				{
					ans[x][y-1]++;
					y--;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else if(d==3)
			{
				if(x-1>0 && x-1<=n && a[x-1][y]==0)
				{
					ans[x-1][y]++;
					x--;
				}
				else
				{
					d=(d+1)%4;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(ans[i][j]>=1) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
