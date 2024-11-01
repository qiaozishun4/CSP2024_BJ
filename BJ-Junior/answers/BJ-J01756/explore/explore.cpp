#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d, cnt;
bool vis[1002][1002];
char a[1002][1002];
const int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);	
	cin>>t;
	while(t--){
		cnt=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i = 1; i <= n; i++){
			memset(vis[i], 0, sizeof(vis[i]));
			for(int j = 1; j <= m; j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		while(k--){	
			int tx=x+dx[d], ty=y+dy[d];
			if(tx>n||tx<1||ty>m||ty<1||a[tx][ty]=='x'){
				d++;
				d%=4;
				continue;
			}
			if(vis[tx][ty]==0){
				vis[tx][ty]=1;
				cnt++;
			}
			x=tx, y=ty;
		}
		cout<<cnt<<endl;
	} 
	return 0;
}