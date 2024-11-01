#include<bits/stdc++.h>
using namespace std;
const int N=10005;
char a[N][N];
int t;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n,m,k,sum=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		int x1,y1,d1;
		a[x][y]='#';
		while(k--)
		{
			if(d==0)
			{
				x1=x;
				y1=y+1;
			}
			else if(d==1)
			{
				x1=x+1;
				y1=y;
			}
			else if(d==2)
			{
				x1=x;
				y1=y-1;
			}
			else if(d==3)
			{
				x1=x-1;
				y1=y;
			}
			if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&a[x1][y1]!='x')
			{
				x=x1;
				y=y1;
				a[x][y]='#';
			}
			else
			{
				d1=(d+1)%4;
				d=d1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]=='#')
					sum++;
		cout<<sum<<endl;
	}
	return 0;
}