#include<bits/stdc++.h>
using namespace std;
void sol();
signed main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) sol();
	return 0;
}
void yd(int &x,int &y,int d){
	switch(d){
		case 0:y++;break;
		case 1:x++;break;
		case 2:y--;break;
		case 3:x--;break;
	}
}
void zd(int &d){
	d=(d+1)%4;
}
void sol(){
	int n,m,k,ans=0,x,y,d;
	char g[1010][1010];
	bool vis[1010][1010];
	scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
	vis[x][y]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	while(k--){
		int nx=x,ny=y;
		yd(nx,ny,d);
		if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x') zd(d);
		else yd(x,y,d);
		vis[x][y]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=vis[i][j];
	printf("%d\n",ans);
}
