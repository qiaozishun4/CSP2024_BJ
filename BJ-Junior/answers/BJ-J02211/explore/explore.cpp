#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,k,cnt=0;
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			bool flag=0;
			if(d0==0)
			{
				if(x0<=n&&x0>=1&&y0+1<=m&&y0+1>=1)
				{						
					if(a[x0][y0+1]!='x')
					{
						flag=1;
						cnt++;
						y0=y0+1;
					}	
				}
				if(flag==0)
				{
					d0=(d0+1)%4;
				}
			}
			else if(d0==1)
			{
				if(x0+1<=n&&x0+1>=1&&y0<=m&&y0>=1)
				{						
					if(a[x0+1][y0]!='x')
					{
						flag=1;
						cnt++;
						x0=x0+1;
					}	
				}
				if(flag==0)
				{
					d0=(d0+1)%4;
				}
			}
			else if(d0==2)
			{
				if(x0<=n&&x0>=1&&y0-1<=m&&y0-1>=1)
				{						
					if(a[x0][y0-1]!='x')
					{
						flag=1;
						cnt++;
						y0=y0-1;
					}	
				}
				if(flag==0)
				{
					d0=(d0+1)%4;
				}
			}
			else if(d0==3)
			{
				if(x0-1<=n&&x0-1>=1&&y0<=m&&y0>=1)
				{						
					if(a[x0-1][y0]!='x')
					{
						flag=1;
						cnt++;
						x0=x0-1;
					}	
				}
				if(flag==0)
				{
					d0=(d0+1)%4;
				}
			}
			if(i==1&&flag==0)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}