#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[1005][1005];
int ans=0;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,sx,sy,sd;
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		ans=1;
		vis[sx][sy]=1;
		int x=sx,y=sy,d=sd;
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(mp[nx][ny] == 'x' || nx<1 || nx>n || ny<1 || ny>m){
				d=(d+1)%4;
			}
			else{
				if(!vis[nx][ny]){
					ans++;
					vis[nx][ny]=1;
				}
				x=nx,y=ny;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
