#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("explore.in","r",stdin);
 	freopen("explore.out","w",stdout);
	int t,f[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	cin>>t;
	while(t--){
		int n,m,k,x,y,d,ans=0;
		char mp[1005][1005];
		bool vis[1005][1005];
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				vis[i][j]=0;
			}
		}
		vis[1][1]=1;
		for(int i=1;i<=k;i++){
			int nx=x+f[d][0],ny=y+f[d][1];
			if(mp[nx][ny]=='x'||nx<1||nx>n||ny<1||ny>m){
				d=(d+1)%4;
			}else{
				x=nx,y=ny;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
//				cout<<vis[i][j];
				if(vis[i][j]&&mp[i][j]=='.'){
					ans++;
				}
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}