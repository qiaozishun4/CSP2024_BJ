#include<bits/stdc++.h>
using namespace std;
char g[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,d;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]=='.') x=nx,y=ny;
			else d=(d+1)%4;
			vis[x][y]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}