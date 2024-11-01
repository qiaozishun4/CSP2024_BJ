#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,x,y,d,ans;
char a[N][N];
int vis[N][N];
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		ans=1;
		while(k--){
			int nx,ny;
			nx=x+dis[d][0];
			ny=y+dis[d][1];
			if(nx>n||ny>m||nx<1||ny<1||a[nx][ny]=='x'){
				d++;
				d%=4;
				continue;
			}
			x=nx;
			y=ny;
			if(!vis[x][y]){
				ans++;
				vis[x][y]=1;
			}
		}
		cout<<ans<<endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
