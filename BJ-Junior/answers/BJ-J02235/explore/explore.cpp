#include<bits/stdc++.h>
using namespace std;
const int N=1E3+1;
bool a[N][N],b[N][N];
int xy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k,x,y,d,s=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				if(c=='.') a[i][j]=0;
				else a[i][j]=1;
			}
		}
		b[x][y]=1;
		while(k--)
		{
			int nx=x+xy[d][0],ny=y+xy[d][1];
			if(nx>n||nx<1||ny>m||ny<1)
			{
				d=(d+1)%4;
				continue;
			}
			if(a[nx][ny]==1)
			{
				d=(d+1)%4;
				continue;
			}
			x=nx;
			y=ny;
			if(b[x][y]==0)
			{
				b[x][y]=1;
				s++;
			}
		}
		cout<<s<<endl;
		memset(b,0,sizeof(b));
	}
	return 0;
}