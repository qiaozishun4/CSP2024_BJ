#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
// T [1,5]
// n,m [1,1e3]
// k [1,1e6]
// x0 [1,n] y0 [1,m]
// d0[0,3]
const int N = 1e3+5;
int T,n,m,k,ix,iy,id;
int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};
string g[N];
bool vis[N][N];
int cnt = 0;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>ix>>iy>>id;
		for(int i=1;i<=n;i++){
			cin>>g[i];
			g[i] = " "+g[i];
		}
		cnt = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)vis[i][j] = 0;
		}
		//
		cnt = 1;
		vis[ix][iy] = 1;
		int x = ix,y = iy,d = id;
		while(k--){
			int xx = x + dx[d];
			int yy = y + dy[d];
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && g[xx][yy]=='.'){ // go
				x = xx;
				y = yy;
				if(!vis[xx][yy])cnt++;
				vis[xx][yy] = 1;
			}else{ // turn
				d = (d+1) % 4;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
