#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
int t,n,m,k,sx,sy,x,y,fx;
int vis[1010][1010];
char mp[1010][1010];
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>sx>>sy>>fx;
		int ant=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				vis[i][j]=0;
			}
		}
		int x=sx,y=sy;
		vis[x][y]=1;
		while(k--){
			if(fx==0){
				if(y+1>=1&&y+1<=m&&mp[x][y+1]!='x'){
					y++;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ant++;
					}						
				}else{
					fx++;
				}
			}else if(fx==1){
				if(x+1>=1&&x+1<=n&&mp[x+1][y]!='x'){
					x++;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ant++;
					}														
				}else{
					fx++;
				}
			}else if(fx==2){
				if(y-1>=1&&y-1<=m&&mp[x][y-1]!='x'){
					y--;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ant++;
					}
				}else{
					fx++;
				}
			}else if(fx==3){
				if(x-1>=1&&x-1<=n&&mp[x-1][y]!='x'){
					x--;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ant++;
					}
				}else{
					fx=0;
				}
			}
		}
		cout<<ant<<"\n";
	}
	return 0;
}