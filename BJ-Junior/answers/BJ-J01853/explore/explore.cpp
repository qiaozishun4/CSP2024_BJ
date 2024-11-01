#include <bits/stdc++.h>
using namespace std;
char c[1002][1002];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
	int T;
	cin>>T;
	while(T)
	{
		int n,m,k,x,y,d,cnt=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1)
				{
					c[n+1][j]='x';
					c[0][j]='x';
				}
				cin>>c[i][j];
			}
			c[i][m+1]='x';
			c[i][0]='x';
		}
		c[x][y]='*';
		while(k--)
		{
			int nx=dx[d]+x,ny=dy[d]+y;
			if(c[nx][ny]=='x')
			d=(d+1)%4;
			else
			{
				x=nx;
				y=ny;
				cnt+=c[x][y]=='.';
				c[x][y]='*';
			}
		}
		cout<<cnt<<endl;
	}
}
