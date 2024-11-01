#include<iostream>
using namespace std;
int T,n,m,k;
char map[1000000][1000000];
int x,y,d,ans,use[1000000][1000000];
int cx[4]={0,1,-1,0};
int cy[4]={1,0,0,-1};
void dfs(int x,int y,int d){
	ans++;
	use[x][y]=1;
	if(k==0)
		return;
	for(int i=0;i<4;i++){
		if(d==i){
			int nx=x+cx[d];
			int ny=y+cy[d];
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&map[nx][ny]=='.'&&use[nx][ny]==0){
				dfs(nx,ny,d);
			}
			else 
				continue;
		}
	}
	k--;
	use[x][y]=0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
			}	
		}
		dfs(x,y,d);
	}
	cout<<ans;
	return 0;
}
