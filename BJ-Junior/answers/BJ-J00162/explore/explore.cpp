#include<bits/stdc++.h>
using namespace std;
inline void file(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
}
int n,m,k,sx,sy,h;
bool vis[10005][10005];
char mp[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	file();
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k>>sx>>sy>>h;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		int x=sx,y=sy;
		vis[sx][sy]=1;
		while(k--){
			int nx=x+dx[h];
			int ny=y+dy[h];
			if(nx<1 || nx>n || ny<1 || ny>m || mp[nx][ny]=='x'){
				h=(h+1)%4;
				continue;
			}
			x=nx,y=ny;
			vis[nx][ny]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}