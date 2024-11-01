#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int T;
int n,m,k;
int sx,sy,sd;
char g[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		vis[sx][sy]=1;
		while(k--){
			int nx=sx+dx[sd];
			int ny=sy+dy[sd];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]=='.'){
				sx=nx;
				sy=ny;
			}else{
				sd=(sd+1)%4;
			}
			vis[sx][sy]=1;
		}
		//cout<<sx<<" "<<sy<<"\n";
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
