#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int n,m,k,ans=1;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		vis[x][y]=1;
		d%=4;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		while(k--){
			if(d==0){
				if(a[x][y+1]=='.'&&x>=1&&x<=n&&y+1>=1&&y+1<=m){
					y++;
					if(!vis[x][y]){
						ans++;
					}
					vis[x][y]=1;
				}
				else{
					d++;
					d%=4;
				}
			}
			else if(d==1){
				if(a[x+1][y]=='.'&&x+1>=1&&x+1<=n&&y>=1&&y<=m){
					x++;
					if(!vis[x][y]){
						ans++;
					}
					vis[x][y]=1;
				}
				else{
					d++;
					d%=4;
				}
			}
			else if(d==2){
				if(a[x][y-1]=='.'&&x>=1&&x<=n&&y-1>=1&&y-1<=m){
					y--;
					if(!vis[x][y]){
						ans++;
					}
					vis[x][y]=1;
				}
				else{
					d++;
					d%=4;
				}
			}
			else{
				if(a[x-1][y]=='.'&&x-1>=1&&x-1<=n&&y>=1&&y<=m){
					x--;
					if(!vis[x][y]){
						ans++;
					}
					vis[x][y]=1;
				}
				else{
					d++;
					d%=4;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
