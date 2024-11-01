#include<bits/stdc++.h>
using namespace std;
char a[1005][105];
bool flag[1005][1005];
int disx[]={0,1,0,-1};
int disy[]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(flag[x][y]==0)
			{
				cnt++;
			}
			flag[x][y]=1;
			int nx=x+disx[d];
			int ny=y+disy[d];
			if(nx>n || nx<1|| ny>m || ny<1)d=(d+1)%4;
			else if(a[nx][ny]=='x')d=(d+1)%4;
			else
			{
				x=nx;
				y=ny;
			}
		}
		if(flag[x][y]==0)cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
