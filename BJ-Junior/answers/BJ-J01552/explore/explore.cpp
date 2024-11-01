#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d,ans;
	cin>>t;
	while(t--)
	{
		ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		char a[n+1][m+1];
		int b[n+1][m+1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				b[i][j]=0;
			}
		b[x][y]=1;
		while(k--)
		{
			if(d==0)
			{
				if(y!=m)
				{
					if(a[x][y+1]=='.')
					{
						y++;
						if(b[x][y]==0)
						{
							ans++;
							b[x][y]=1;
						}
					}
					else d++;
				}
				else d++;
			}
		else if(d==1)
		{
			if(x!=n)
			{
				if(a[x+1][y]=='.')
				{
					x++;
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]=1;
					}
				}
				else d++;
			}
			else d++;
		}
		else if(d==2)
		{
			if(y!=0)
			{
				if(a[x][y-1]=='.')
				{
					y--;
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]=1;
					}
				}
				else d++;
			}
			else d++;
		}
		else if(d==3)
		{
			if(x!=0)
			{
				if(a[x-1][y]=='.')
				{
					x--;
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]=1;
					}
				}
				else d=0;
			}
			else d=0;
		}
	}
	cout<<ans<<endl;
}
	return 0;
}
