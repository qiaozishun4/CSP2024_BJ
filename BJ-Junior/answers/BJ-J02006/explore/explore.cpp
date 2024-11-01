#include<bits/stdc++.h>
using namespace std;
int n , m , k ;
char g[1005][1005];
bool vis[1005][1005];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ans = 0 ;
void dfs(int x , int y , int s , int d){
	if(s==k){
		return ;
	}
	if(d==-1){
		d=3;
	}
	int nx = x+dx[d] , ny = y+dy[d] ;
	if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x'||vis[nx][ny]==1){
		dfs(x,y,s+1,d-1);
	}
	ans++;
	vis[nx][ny]=1;
	dfs(nx,ny,s+1,d);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t ;
	cin >> t ;
	while(t--){
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		ans = 0 ;
		int x , y , d;
		cin >> n >> m >> k ;
		cin >> x >> y >> d ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> g[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,0,d);
		cout << ans << endl ;
	}
	return 0 ;
}
