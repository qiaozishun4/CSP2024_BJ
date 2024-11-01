#include <bits/stdc++.h>
using namespace std;
int h[1005][1005],v[1005][1005],ans;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) v[i][j]=h[i][j]=0;
	int x,y,d;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		char tm;
		cin>>tm;
		if(tm=='x') h[i][j]=1;
	}
	while(k--)
	{

		v[x][y]=1;
		int nx,ny;
		if(d==0){nx=x,ny=y+1;}
		if(d==1){nx=x+1,ny=y;}
		if(d==2){nx=x,ny=y-1;}
		if(d==3){nx=x-1,ny=y;}
		if(nx>=1 and nx<=n and ny>=1 and ny<=m and !h[nx][ny])
		{
			x=nx;
			y=ny;
			v[x][y]=1;
		}
		else d=(d+1)%4;
		//cout<<x<<" "<<y<<" "<<d<<endl;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(v[i][j]) ans++;
	cout<<ans<<endl;
	ans=0;
}
    return 0;
}
