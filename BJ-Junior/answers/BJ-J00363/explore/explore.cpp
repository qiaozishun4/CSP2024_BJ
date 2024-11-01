#include<bits/stdc++.h>
using namespace std;
char g[1005][1005];
bool vis[1005][1005];
int main(){
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(g[x][y+1]=='.'&&x>0&&x<=n&&y+1>0&&y+1<=m){
					y++;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==1){
				if(g[x+1][y]!='x'&&x+1>0&&x+1<=n&&y>0&&y<=m){
					x++;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}else{
					d=(d+1)%4;
				}
			}else if(d==3){
				if(g[x-1][y]!='x'&&x-1>0&&x-1<=n&&y>0&&y<=m){
					x--;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}else{
					d=(d+1)%4;
				}
			}else{
				if(g[x][y-1]!='x'&&x>0&&x<=n&&y-1>0&&y-1<=m){
					y--;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}else{
					d=(d+1)%4;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

