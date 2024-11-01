#include <bits/stdc++.h>
using namespace std;
long long T,ans;
long long n,m,k;
long long x,y,d;
long long vis[1055][1055];
char maps[1055][1055];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans = 1;
		memset(maps,0,sizeof maps);
		memset(vis,0,sizeof vis);
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y] = 1;
		for(long long i = 1;i <= n;i++){
			for(long long j = 1;j <= m;j++){
				cin>>maps[i][j];
			}
		}
		while(k--){
			long long xx,yy;
			if(d == 0){
				xx = x;
				yy = y + 1;
			}
			if(d == 1){
				xx = x + 1;
				yy = y;
			}
			if(d == 2){
				xx = x;
				yy = y - 1;
			}
			if(d == 3){
				xx = x - 1;
				yy = y;
			}
			if(xx <= n && xx >= 1 && yy <= m && yy >= 1 && maps[xx][yy] == '.'){
				x = xx;
				y = yy;
				if(vis[x][y] == 0){
					ans++;
				}
				vis[x][y] = 1;
			}else{
				d = (d + 1) % 4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
