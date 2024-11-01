#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int dx[4] = {0,1,0,-1};
		int dy[4] = {1,0,-1,0};
		bool a[1007][1007];
		bool vis[1007][1007];
		int n,m,k;
		int x,y,d;
		memset(vis,0,sizeof(vis));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		vis[x][y]=1;
		int cnt=1;
		for(int i=1;i<=n;++i){
			string s;
			cin >> s;
			for(int j=0;j<m;++j){
				if(s[j] == '.'){
					a[i][j+1] = 1;
				}
				else{
					a[i][j+1] = 0;
				}
			}
		}
		for(int i=1;i<=k;++i){
			int nx=x+dx[d];
			int ny=y+dy[d];
			//cout << nx << ' ' << ny << ' ';
			if(nx<1||nx>n||ny<1||ny>m||a[nx][ny] == 0){
				d = (d+1)%4;
			}
			else{
				x=nx;
				y=ny;
				if(vis[nx][ny]==0){
					vis[nx][ny]=1;
					cnt++;
				}
			}
			//cout << d << endl;
		}
		cout << cnt << endl;
	}
	return 0;
}
