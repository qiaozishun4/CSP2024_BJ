#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int sx,sy,sd,ans;
char mp[1005][1005];
int vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int x,int y){
	if(x<1 || x>n || y<1 || y>m) return false;
	if(mp[x][y]=='x') return false;
	return true;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		cin >> sx >> sy >> sd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> mp[i][j];
			}
		}
		ans=0;
		int step=0;
		int x=sx,y=sy,d=sd;
		memset(vis,0,sizeof(vis));
		while(step<=k){
			if(!vis[x][y]) ans++;
			vis[x][y]=1;
			int nx=x+dx[d],ny=y+dy[d];
			if(check(nx,ny)) x=nx,y=ny;
			else d=(d+1)%4;
			step++;
		}
		cout << ans << endl;
	}
	return 0;
}