#include<iostream>
#include<cstring>
using namespace std;
char a[1010][1010];
int ans[1010][1010]={0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		memset(ans,0,sizeof(ans));
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		ans[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			int nx=x,ny=y;
			if(d==0)ny++;
			if(d==1)nx++;
			if(d==2)ny--;
			if(d==3)nx--;
			if(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x')
			{
				d++;
				d%=4;
				continue;
			}
			x=nx;
			y=ny;
			ans[x][y]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ans[i][j])cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
