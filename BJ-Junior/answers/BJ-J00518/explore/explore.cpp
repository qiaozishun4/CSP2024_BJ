#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
bool vis[1010][1010];
int nx,ny,nd,n,m;
void move()
{
	if(nx==0||ny==0) return;
	if(nd==0) ny++;
	else if(nd==1) nx++;
	else if(nd==2) ny--;
	else if(nd==3) nx--;
}
bool valid(int x,int y)
{
	if(x>n)
	{
		//cout<<"Move failed. Reason:Out of the Map(X axis>n)\n";
		return 0;
	}
	if(x<1)
	{
		//cout<<"Move failed. Reason:Out of the Map(X axis<1)\n";
		return 0;
	}
	if(y>m)
	{
		//cout<<"Move failed. Reason:Out of the Map(Y axis>m)\n";
		return 0;
	}
	if(y<1)
	{
		//cout<<"Move failed. Reason:Out of the Map(Y axis<1)\n";
		return 0;
	} 
	if(mp[x][y]!='.') 
	{
		//cout<<"Move failed. Reason:The place isn't empty\n";
		return 0;
	}
	//cout<<"Moved Success\n";
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int i,j,k,T;
	cin>>T;
	while(T--)
	{
		int ans=0,x,y,d;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++) cin>>mp[i][j];
		}
		//for(i=1;i<=n;i++)
		//{
		//	for(j=1;j<=m;j++) cout<<mp[i][j];
		//	cout<<endl;
		//}
		nx=x,ny=y,nd=d;
		vis[nx][ny]=1;
		for(i=1;i<=k;i++)
		{
			nx=x,ny=y,nd=d;
			move();
			//cout<<"NX:"<<nx<<" NY:"<<ny<<" Nd:"<<nd<<endl;
			if(!valid(nx,ny))
			{
				nd=(d+1)%4;
				nx=x,ny=y;
			}
			x=nx,y=ny,d=nd;
			vis[x][y]=1;
			//cout<<"X:"<<x<<" Y:"<<y<<" d:"<<d<<endl<<endl;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
}