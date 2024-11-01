#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=1e3+10;
char c[N][N];
bool vis[N][N];

int cnt=1;

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);

	int T;
	cin>>T;

	while (T--)
	{
		cnt=1;
		memset(vis,0,sizeof vis);
		
		int n,m,k;
		cin>>n>>m>>k;

		int x,y,d;
		cin>>x>>y>>d;
		vis[x][y]=1;

		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin>>c[i][j];

		for (int i=0;i<k;i++)
		{
			int sx=x,sy=y;
			
			if (d==0) y++;
			if (d==1) x++;
			if (d==2) y--;
			if (d==3) x--;

			if (1<=x&&x<=n&&1<=y&&y<=m&&c[x][y]=='.')
			{
				if (!vis[x][y])
				{
					cnt++;
					vis[x][y]=true;
				//	cout<<'+';
				}
				//cout<<"move to "<<x<<' '<<y<<'\n';
			}
			else
			{
				x=sx,y=sy,d=(d+1)%4;
			//	cout<<"stay at "<<x<<' '<<y<<'\n';
			}

		}
		cout<<cnt<<'\n';
		//	<<'\n';
	}

	return 0;
}